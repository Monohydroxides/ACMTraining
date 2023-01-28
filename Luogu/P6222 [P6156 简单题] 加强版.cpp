#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;

const int N = 1e7;
const long long mod = 1ll << 32;

int T;
int n, k;
int f[N * 2 + 1];
int tpowk[N * 2 + 1];
int primes[N * 2 + 1], cnt;
bool st[N * 2 + 1];

long long qmi(int a, int b){
    long long res = 1;
    while(b){
        if(b & 1)   res = (i128) res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init(){
    f[1] = 1, tpowk[1] = 1;
    for(int i = 2; i <= n << 1; ++i){
        if(!st[i])  primes[cnt++] = i, f[i] = i - 1, tpowk[i] = qmi(i, k);
        for(int j = 0; primes[j] * i <= n << 1; ++j){
            st[primes[j] * i] = 1;
            tpowk[primes[j] * i] = (i128) tpowk[primes[j]] * tpowk[i] % mod;
            if(i % primes[j] == 0){
                int q = i / primes[j];
                if(q % primes[j]){
                    f[primes[j] * i] = (i128) (mod - primes[j]) * f[q] % mod;
                }
                break;
            }
            f[primes[j] * i] = (i128) f[i] * (primes[j] - 1) % mod;
        }
    }
    for(int i = 1; i <= n << 1; ++i){
        f[i] = ((f[i - 1] + (i128) f[i] * tpowk[i] % mod) + mod) % mod;
        tpowk[i] = ((tpowk[i - 1] + tpowk[i]) % mod + mod) % mod;
    }
    for(int i = 1; i <= n << 1; ++i){
        tpowk[i] = ((tpowk[i - 1] + tpowk[i]) % mod + mod) % mod;
    }
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> T >> n >> k;
    init();
    while (T--) {
        long long res = 0;
        cin >> n;
        for(int l = 1, r; l <= n; l = r + 1){
            r = n / (n / l);
            res = (res + (i128) (((f[r] - f[l - 1]) % mod + mod) % mod) * (((tpowk[2 * (n / l)] - 2 * tpowk[(n / l)]) % mod + mod) % mod) % mod) % mod;
        }
        cout << res << endl;
    }
    return 0;
}