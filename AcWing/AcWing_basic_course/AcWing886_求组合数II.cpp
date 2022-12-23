#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5;
int mod = 1e9 + 7;

int fact[N], infact[N];
int n;

int qmi(int a, int b, int p){
    int res = 1 % p;
    while(b){
        if(b & 1){
            res = (LL) res * a % p;
        }
        a = (LL) a * a % p;
        b >>= 1;
    }
    return res;
}

void init(){
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; ++i){
        fact[i] = (LL) fact[i - 1] * i % mod;
        infact[i] = (LL) infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

int main(){
    cin >> n;
    int a, b;
    init();
    while(n--){
        cin >> a >> b;
        cout << (LL)fact[a] * infact[b] % mod * infact[a - b] % mod << endl; 
    }
    return 0;
}
