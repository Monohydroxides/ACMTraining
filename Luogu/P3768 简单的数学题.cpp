#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e6 + 10;

ll n;
int inv6;
int mod = 1e9 + 7;
int primes[N], cnt;
bool st[N];
int phi[N];
int S[N];
unordered_map<ll, ll> overflowS;

inline ll qmi(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1)   res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

inline void init() {
    phi[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] * i < N; ++j) {
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) {
                phi[primes[j] * i] = primes[j] * phi[i];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
    for(int i = 1; i < N; ++i) {
        S[i] = (S[i - 1] + (ll) i * i % mod * phi[i] % mod) % mod;
    }
}

inline ll calc1(ll x) {
    x %= mod;
    return ((1 + x) * x / 2 % mod * ((1 + x) * x / 2 % mod)) % mod;
}

inline ll calc2(ll x) {
    x %= mod;
    return x * (x + 1) % mod * (2 * x + 1) % mod * inv6 % mod;
}

ll getS(ll x) {
    if(x < N)   return S[x];
    if(overflowS.count(x))  return overflowS[x];
    ll res = calc1(x);
    for(ll l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        res = res - getS(x / l) * ((calc2(r) - calc2(l - 1) + mod) % mod) % mod;
        res = (res + mod) % mod;
    }
    overflowS[x] = res;
    return res;
}

int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> mod >> n;
    inv6 = qmi(6, mod - 2);
    init();
    ll res = 0;
    for(ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        res = (res + (ll) calc1(n / l) * ((getS(r) - getS(l - 1) + mod) % mod) % mod) % mod;
    }
    cout << res << endl;
    return 0;
}