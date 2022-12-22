#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll w, n, k;
int mod = 1e9 + 7;

ll qmi(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1)   res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

ll qmi1(ll p, ll q, ll b){
    ll resp = 1, resq = 1;
    ll res = 0;
    while(b){
        if(b & 1){
            resp = resp * p % mod;
            resq = resq * q % mod;
            res = resp * qmi(resq, mod - 2)  % mod;
        }
        p = p * p % mod;
        q = q * q % mod;
        b >>= 1;
    }
    return res % mod;
}

int main(){
    cin >> w >> n >> k;
    ll res = qmi1(1, 2, k);
    res = w * res % mod;
    cout << res << endl;
    return 0;
}