#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;
using i64 = long long;
int norm(int x) {
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
    }
    return x;
}
template<typename T>
T power(T a, int b) {
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
    Pot operator-() const {
        return Pot(norm(mod - x));
    }
    Pot inv() const {
        assert(x != 0);
        return power(*this, mod - 2);
    }
    Pot &operator*=(const Pot &rhs) {
        x = i64(x) * rhs.x % mod;
        return *this;
    }
    Pot &operator+=(const Pot &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Pot &operator-=(const Pot &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Pot &operator/=(const Pot &rhs) {
        return *this *= rhs.inv();
    }
    friend Pot operator*(const Pot &lhs, const Pot &rhs) {
        Pot res = lhs;
        res *= rhs;
        return res;
    }
    friend Pot operator+(const Pot &lhs, const Pot &rhs) {
        Pot res = lhs;
        res += rhs;
        return res;
    }
    friend Pot operator-(const Pot &lhs, const Pot &rhs) {
        Pot res = lhs;
        res -= rhs;
        return res;
    }
    friend Pot operator/(const Pot &lhs, const Pot &rhs) {
        Pot res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Pot &a) {
        i64 v;
        is >> v;
        a = Pot(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Pot &a) {
        return os << a.val();
    }
};

std::vector<int> rev;
std::vector<Pot> roots{0, 1};
void dft(std::vector<Pot> &a) {
    int n = a.size();
    
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (rev[i] < i) {
            std::swap(a[i], a[rev[i]]);
        }
    }
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            Pot e = power(Pot(3), (mod - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * e;
            }
            k++;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                Pot u = a[i + j];
                Pot v = a[i + j + k] * roots[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}
void idft(std::vector<Pot> &a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    Pot inv = (1 - mod) / n;
    for (int i = 0; i < n; i++) {
        a[i] *= inv;
    }
}
struct Poly {
    std::vector<Pot> a;
    Poly() {}
    Poly(const std::vector<Pot> &a) : a(a) {}
    Poly(const std::initializer_list<Pot> &a) : a(a) {}
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
    Poly mulxk(int k) const {
        auto b = a;
        b.insert(b.begin(), k, 0);
        return Poly(b);
    }
    Poly modxk(int k) const {
        k = std::min(k, size());
        return Poly(std::vector<Pot>(a.begin(), a.begin() + k));
    }
    Poly divxk(int k) const {
        if (size() <= k) {
            return Poly();
        }
        return Poly(std::vector<Pot>(a.begin() + k, a.end()));
    }
    friend Poly operator+(const Poly &a, const Poly &b) {
        // 多项式加法
        std::vector<Pot> res(std::max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i++) {
            res[i] = a[i] + b[i];
        }
        return Poly(res);
    }
    friend Poly operator-(const Poly &a, const Poly &b) {
        // 多项式减法
        std::vector<Pot> res(std::max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i++) {
            res[i] = a[i] - b[i];
        }
        return Poly(res);
    }
    friend Poly operator*(Poly a, Poly b) {
        // 多项式乘法
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
    friend Poly operator*(Pot a, Poly b) {
        // 点值乘多项式
        for (int i = 0; i < int(b.size()); i++) {
            b[i] *= a;
        }
        return b;
    }
    friend Poly operator*(Poly a, Pot b) {
        // 多项式乘点值
        for (int i = 0; i < int(a.size()); i++) {
            a[i] *= b;
        }
        return a;
    }
    Poly &operator+=(Poly b) {
        return (*this) = (*this) + b;
    }
    Poly &operator-=(Poly b) {
        return (*this) = (*this) - b;
    }
    Poly &operator*=(Poly b) {
        return (*this) = (*this) * b;
    }
    Poly deriv() const {
        // 多项式求导
        if (a.empty()) {
            return Poly();
        }
        std::vector<Pot> res(size() - 1);
        for (int i = 0; i < size() - 1; ++i) {
            res[i] = (i + 1) * a[i + 1];
        }
        return Poly(res);
    }
    Poly integr() const {
        // 多项式积分
        std::vector<Pot> res(size() + 1);
        for (int i = 0; i < size(); ++i) {
            res[i + 1] = a[i] / (i + 1);
        }
        return Poly(res);
    }
    Poly inv(int m) const {
        Poly x{a[0].inv()};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (Poly{2} - modxk(k) * x)).modxk(k);
        }
        return x.modxk(m);
    }
    Poly log(int m) const {
        return (deriv() * inv(m)).integr().modxk(m);
    }
    Poly exp(int m) const {
        Poly x{1};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (Poly{1} - x.log(k) + modxk(k))).modxk(k);
        }
        return x.modxk(m);
    }
    Poly pow(int k, int m) const {
        int i = 0;
        while (i < size() && a[i].val() == 0) {
            i++;
        }
        if (i == size() || 1LL * i * k >= m) {
            return Poly(std::vector<Pot>(m));
        }
        Pot v = a[i];
        auto f = divxk(i) * v.inv();
        return (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);
    }
    Poly sqrt(int m) const {
        Poly x{1};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((mod + 1) / 2);
        }
        return x.modxk(m);
    }
    Poly mulT(Poly b) const {
        if (b.size() == 0) {
            return Poly();
        }
        int n = b.size();
        std::reverse(b.a.begin(), b.a.end());
        return ((*this) * b).divxk(n - 1);
    }
    std::vector<Pot> eval(std::vector<Pot> x) const {
        if (size() == 0) {
            return std::vector<Pot>(x.size(), 0);
        }
        const int n = std::max(int(x.size()), size());
        std::vector<Poly> q(4 * n);
        std::vector<Pot> ans(x.size());
        x.resize(n);
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                q[p] = Poly{1, -x[l]};
            } else {
                int m = (l + r) / 2;
                build(2 * p, l, m);
                build(2 * p + 1, m, r);
                q[p] = q[2 * p] * q[2 * p + 1];
            }
        };
        build(1, 0, n);
        std::function<void(int, int, int, const Poly &)> work = [&](int p, int l, int r, const Poly &num) {
            if (r - l == 1) {
                if (l < int(ans.size())) {
                    ans[l] = num[0];
                }
            } else {
                int m = (l + r) / 2;
                work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
                work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
            }
        };
        work(1, 0, n, mulT(q[1].inv(n)));
        return ans;
    }
};


const int inv100 = 828542813;
int n;
vector<Pot> P, C, W, invP, sumW, invsumW;
vector<Pot> a, b, fa, fb;
vector<Pot> ba, bb, bw;

void cdq(int l, int r) {
    if(l == r) {
        if(l) {
            a[l + 1] = (a[l] - (1 - P[l]) * fa[l] * invsumW[l]) * invP[l];
            b[l + 1] = (b[l] - C[l] - (1 - P[l]) * fb[l] * invsumW[l]) * invP[l];
        }
        return;
    }
    int mid = l + r >> 1;
    cdq(l, mid);
    int k = 1;
    while(k < r - l + 1) k <<= 1;
    ba.resize(k), bb.resize(k), bw.resize(k);
    for(int i = 0; i < k; ++i) {
        ba[i] = 0, bb[i] = 0, bw[i] = 0;
    }
    for(int i = l; i <= mid; ++i) {
        ba[i - l] = a[i], bb[i - l] = b[i];
    }
    for(int i = 1; i <= r - l; ++i) {
        bw[i] = W[i];
    }
    Poly pba = Poly(ba), pbw = Poly(bw), pbb = Poly(bb);
    Poly pbaw = pba * pbw;
    Poly pbbw = pbb * pbw;
    for(int i = mid + 1; i <= r; ++i) {
        fa[i] = fa[i] + pbaw[i - l];
        fb[i] = fb[i] + pbbw[i - l];
    }
    cdq(mid + 1, r);
}

void work() {
    scanf("%d", &n);
    // printf("%d\n", n);

    P.resize(n), C.resize(n), W.resize(n), invP.resize(n), sumW.resize(n), invsumW.resize(n);
    a.resize(n + 1), b.resize(n + 1), fa.resize(n), fb.resize(n);
    ba.resize(n), bb.resize(n), bw.resize(n);

    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &P[i - 1], &C[i - 1]);
        P[i - 1] = P[i - 1] * inv100;
        invP[i - 1] = power(P[i - 1], mod - 2);
    }

    sumW[0] = 0, invsumW[0] = 0;
    for(int i = 1; i < n; ++i) {
        scanf("%d", &W[i]);
        sumW[i] = sumW[i - 1] + W[i];
        invsumW[i] = power(sumW[i], mod - 2);
    }
    for(int i = 0; i <= n; ++i) {
        fa[i] = fb[i] = 0;
    }

    a[0] = 1, b[0] = 0;
    a[1] = 1, b[1] = mod - C[0];
    cdq(0, n - 1);
    Pot ans = (mod - b[n]) * power(a[n], mod - 2);
    printf("%d\n", ans.x);
}

int main() {
    int T;
    // freopen("tmp.in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        // printf("%d: ", T);
        work();
    }
    return 0;
}
