#pragma optimize(2)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e12 + 10, M = 1e7 + 10, mod = 4179340454199820289;

ll m;
ll primes[M], cnt;
ll inv[65];
bool st[M];

ll mul(ll a, ll b) {
    return (a * b - (unsigned long long)((long double) a / mod * b) * mod + mod) % mod;
}

ll qmi(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1)   res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

void init() {
    for(int k = 1; k <= 64; ++k) {
        inv[k] = qmi(k, mod - 2);
    }
    ll mx = sqrt(N);
    for(ll i = 2; i <= mx + 5; ++i) {
        if(!st[i])  primes[cnt++] = i;
        for(ll j = 0; i * primes[j] <= mx + 5; ++j) {
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  break;
        }
    }
}

ll calch(ll p, ll k, ll pk) {
    return mod - mul(pk, mul(inv[k], inv[k - 1]));
}

ll work(ll n, ll idx, ll hd) {
    ll res = mul(mul(n, mul(n + 1, inv[2])), hd);
    for(ll i = idx; i < cnt; ++i) {
        ll prime = primes[i], k = 1;
        ll cur = n / prime, pk = prime;
        if(cur < prime) break;
        while(cur >= prime) {
            cur /= prime;
            pk *= prime;
            ++k;
            res = (res + work(cur, i + 1, mul(hd, calch(prime, k, pk)))) % mod;
            res = (res + mod) % mod;
        }
    }
    return res;
}

int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    init();
    while(T--) {
        scanf("%lld", &m);
        printf("%lld\n", mul(work(m, 0, 1), qmi(m, mod - 2)));
    }
    return 0;
}