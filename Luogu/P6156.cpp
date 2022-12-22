#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5 * 1e6 + 10, mod = 998244353;

ll n, k;
int f[N * 2 + 10], primes[N * 2 + 10], cnt, st[N * 2 + 10], tpowk[N * 2 + 10];

int qmi(ll a, ll b){
    int res = 1;
    while(b){
        if(b & 1)   res = (ll) res * a % mod;
        a = (ll) a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void init(){
    f[1] = 1, tpowk[1] = 1;
    for(int i = 2; i <= N << 1; ++i){
        if(!st[i])  primes[cnt++] = i, f[i] = i - 1, tpowk[i] = qmi(i, k);
        for(int j = 0; primes[j] * i <= N << 1; ++j){
            st[primes[j] * i] = 1;
            tpowk[primes[j] * i] = (ll) tpowk[primes[j]] * tpowk[i] % mod;
            if(i % primes[j] == 0){
                int q = i / primes[j];
                if(q % primes[j]){
                    f[primes[j] * i] = (ll) (mod - primes[j]) * f[q] % mod;
                }
                break;
            }
            f[primes[j] * i] = (ll) f[i] * (primes[j] - 1) % mod;
        }
    }
    for(int i = 1; i <= N << 1; ++i){
        f[i] = ((((ll) f[i - 1] + (ll) f[i] * tpowk[i] % mod) + mod) % mod)% mod;
        tpowk[i] = ((((ll) tpowk[i - 1] + tpowk[i]) % mod + mod) % mod) % mod;
    }
    for(int i = 1; i <= N << 1; ++i){
        tpowk[i] = (((ll) tpowk[i - 1] + tpowk[i]) % mod + mod) % mod;
    }
}

int main(){
    cin >> n >> k;
    init();
    ll res = 0;
    for(int l = 1, r; l <= n; l = r + 1){
        r = n / (n / l);
        res = (res + (ll) ((((ll) f[r] - f[l - 1]) % mod + mod) % mod) * ((((ll) tpowk[2 * (n / l)] - 2 * tpowk[(n / l)]) % mod + mod) % mod) % mod) % mod;
    }
    cout << res << endl;
    return 0;
}