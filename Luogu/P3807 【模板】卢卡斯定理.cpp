#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, m, p;

int qmi(int a, int b){
    int res = 1 % p;
    while(b){
        if(b & 1)   res = (LL) res * a % p;
        a = (LL) a * a % p;
        b >>= 1;
    }
    return res;
}

LL comb(int a, int b){
    LL res = 1;
    if(a < b)   return 0;
    for(int i = a, j = 1; j <= b; ++j, --i){
        res = res * i % p;
        res = res * qmi(j, p - 2) % p;
    }
    return res;
}

LL lucas(int a, int b){
    if(a < p && b < p)  return (LL)comb(a, b);
    else    return (LL)comb(a % p, b % p) * lucas(a / p, b / p) % p;
}

void work(){
    cin >> n >> m >> p;
    cout << lucas(n + m, m) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)  work();
    return 0;
}