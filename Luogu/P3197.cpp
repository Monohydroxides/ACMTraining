#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int mod = 100003;

LL qmi(LL a, LL b){
    LL res = 1 % mod;
    while(b){
        if(b & 1)   res = (LL) res * a % mod;
        b >>= 1;
        a = (LL) a * a % mod;
    }
    return res;
}

int main(){
    LL n, m;
    cin >> m >> n;
    cout << ((qmi(m, n) - qmi(m - 1, n - 1) * m) % mod + mod) % mod << endl;
    return 0;
}