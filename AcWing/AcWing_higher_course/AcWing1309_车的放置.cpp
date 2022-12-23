#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int mod = 100003;

int a, b, c, d, k;

int qmi(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)   res = (LL) res * a % mod;
        a = (LL) a * a % mod;
        b >>= 1;
    }
    return res;
}

int A(int a, int b){
    if(a < b) return 0;
    int res = 1;
    for(int i = 1; i <= b; ++i){
        res = (LL) res * a % mod;
        a--;
    }
    return res;
}

int comb(int a, int b){
    if(a < b) return 0;
    int res = 1;
    for(int i = 1, j = a; i <= b; ++i, --j){
        res = (LL) res * j % mod;
        res = (LL) res * qmi(i, mod - 2) % mod;
    }
    return res;
}

int C(int a, int b){
    if(a < mod && b < mod)  return comb(a, b);
    return (LL)C(a % mod, b % mod) * comb(a / mod, b / mod) % mod;
}

int main(){
    cin >> a >> b >> c >> d >> k;
    LL res = 0;
    for(int i = 0; i <= k; ++i){
        // cout << C(b, i) << " " << A(a, i) << " " << C(d, k - i) << " " << A(a + c - i, k - i) << endl;
        res = (res + (LL)C(b, i) * A(a, i) % mod * C(d, k - i) * A(a + c - i, k - i) % mod) % mod;
        // cout << res << endl;
    }
    cout << res << endl;
    return 0;
}
