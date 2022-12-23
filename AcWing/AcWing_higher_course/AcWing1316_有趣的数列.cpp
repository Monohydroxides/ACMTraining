#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, mod;

int st[2000010], primes[2000010], cnt;

int qmi(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)   res = (LL) res * a % mod;
        a = (LL) a * a % mod;
        b >>= 1;
    }
    return res;
}

int get(int a, int p){
    int res = 0;
    while(a){
        res += a / p;
        a /= p;
    }
    return res;
}

int C(int a, int b){
    int res = 1;
    for(int i = 0; i < cnt; ++i){
        int p = primes[i];
        int t = get(a, p) - get(b, p) - get(a - b, p);
        // cout << t << endl;
        res = (LL) res * qmi(p, t) % mod;
    }
    return res;
}

int main(){
    cin >> n >> mod;

    for(int i = 2; i <= 2 * n; ++i){
        if(!st[i])   primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= 2 * n; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  break;
        }
    }

    cout << ((C(2 * n, n) - C(2 * n, n - 1)) % mod + mod) % mod << endl;
    return 0;
}


