#include <bits/stdc++.h>
using namespace std;

constexpr int P = 1004535809;
using i64 = long long;
int norm(int x) {
    if (x < 0)
        x += P;

    if (x >= P)
        x -= P;

    return x;
}

template <typename T> T power(T a, int b) {
    T res = 1;

    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }

    return res;
}

struct Pot {
    int x;
    Pot(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Pot inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Pot &operator *= (const Pot &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Pot &operator += (const Pot &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Pot &operator -= (const Pot &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Pot &operator /= (const Pot &rhs) {
        return *this *= rhs.inv();
    }
    friend Pot operator + (const Pot &lhs, const Pot &rhs) {
        Pot res = lhs;
        res += rhs;
        return res;
    }
    friend Pot operator - (const Pot &lhs, const Pot &rhs) {
        Pot res = lhs;
        res -= rhs;
        return res;
    }
    friend Pot operator * (const Pot &lhs, const Pot &rhs) {
        Pot res = lhs;
        res *= rhs;
        return res;
    }
    friend Pot operator / (const Pot &lhs, const Pot &rhs) {
        Pot res = lhs;
        res /= rhs;
        return res;
    }
};

vector<int> rev;
vector<Pot> roots{0, 1};

void dft(vector<Pot> &a) {
    int n = a.size();

    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);

        for (int i = 0; i < n; ++i) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (rev[i] < i) {
            swap(a[i], a[rev[i]]);
        }
    }

    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);

        while ((1 << k) < n) {
            Pot e = power(Pot(3), (P - 1) >> (k + 1));

            for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * e;
            }

            k++;
        }
    }

    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                Pot u = a[i + j];
                Pot v = a[i + j + k] * roots[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}

void idft(vector<Pot> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end());
    dft(a);
    Pot inv = (1 - P) / n;

    for (int i = 0; i < n; ++i) {
        a[i] *= inv;
    }
}

struct Poly {
    vector<Pot> a;
    Poly() {}
    Poly(const vector<Pot> &a) : a(a) {}
    int size() const {
        return a.size();
    }
    void resize(int n) {
        a.resize(n);
    }
    Pot operator[](int idx) const {
        if (idx < size()) {
            return a[idx];
        } else {
            return 0;
        }
    }
    Pot &operator[](int idx) {
        return a[idx];
    }
    friend Poly operator* (Poly a, Poly b) {
        if (a.size() == 0 || b.size() == 0) {
            return Poly();
        }

        int sz = 1, tot = a.size() + b.size() - 1;

        while (sz < tot) {
            sz *= 2;
        }

        a.a.resize(sz);
        b.a.resize(sz);
        dft(a.a);
        dft(b.a);

        for (int i = 0; i < sz; ++i) {
            a.a[i] = a[i] * b[i];
        }

        idft(a.a);
        a.resize(tot);
        return a;
    }
    Poly divxk(int k) const {
        if (size() <= k) {
            return Poly();
        }

        return Poly(vector<Pot>(a.begin() + k, a.end()));
    }
    Poly mulT(Poly b) const {
        if (b.size() == 0) {
            return Poly();
        }

        int n = b.size();
        reverse(b.a.begin(), b.a.end());
        return ((*this) * b).divxk(n - 1);
    }
};

int n, m, s;
vector<Pot> fac, invfac;
vector<Pot> b, c;

Pot Comb(int a, int b) {
    if (a < b)
        return 0;

    return fac[a] * invfac[b] * invfac[a - b];
}

void init() {
    fac.resize(max(n, m) + 1), invfac.resize(max(n, m) + 1);
    fac[0] = fac[1] = 1;

    for (int i = 2; i <= max(n, m); ++i) {
        fac[i] = fac[i - 1] * Pot(i);
    }

    invfac[max(n, m)] = power(fac[max(n, m)], P - 2);

    for (int i = max(n, m); i >= 1; --i) {
        invfac[i - 1] = invfac[i] * Pot(i);
    }
}

int main() {
    cin >> n >> m >> s;

    init();

    int lim = min(n / s, m);

    b.resize(lim + 1);
    c.resize(lim + 1);

    for (int i = 0; i <= lim; ++i) {
        b[i] = fac[i] * Comb(m, i) * fac[n] * invfac[n - i * s] * power(invfac[s], i) * power(Pot(m - i), n - i * s);
        c[i] = ((i & 1) ? Pot(-1) : Pot(1)) * invfac[i];
        // b.push_back(fac[i] * Comb(m, i) * fac[n] * invfac[n - i * s] * power(invfac[s], i) * power(Pot(m - i), n - i * s));
    }

    fac.clear();
    auto a = Poly(b).mulT(c);
    b.clear();
    c.clear();

    Pot res(0);
    int x;

    for (int i = 0; i <= lim; ++i) {
        cin >> x;
        res += a[i] * invfac[i] * Pot(x);
    }

    cout << res.val() << '\n';
    return 0;
}