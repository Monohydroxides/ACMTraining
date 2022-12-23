#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int n;

int qmi(int a, int b, int p){
    int res = 1 % p;
    while(b){
        if(b & 1)   res = (LL) res * a % p;
        a = (LL) a * a % p;
        b >>= 1;
    }
    return res;
}

int catalan(int x){
    int a = 2 * x, b = x;
    int res = 1;
    for(int i = a; i > a - b; --i)  res = (LL) res * i % mod;
    for(int i = 1; i <= b; ++i) res = (LL) res * qmi(i, mod - 2, mod) % mod;
    res = (LL) res * qmi(x + 1, mod - 2, mod) % mod;
    return res;
}

int main(){
    cin >> n;
    cout << catalan(n) << endl;
}
