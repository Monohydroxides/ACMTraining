#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int mod = 200907;

int qmi(int a, int b, int k){
    int res = 1 % k;
    while(b){
        if(b & 1)   res = (LL)res * a % k;
        b >>= 1;
        a = (LL)a * a % k;
    }
    return res;
}

void work(){
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if(b - a == c - b){
        int d = b - a;
        cout << (a + ((LL)(k - 1) * d) % mod) % mod << endl;
    }else{
        int res = qmi(b / a, k - 1, mod);
        cout << (LL)a * res % mod << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--)  work();
    return 0;
}
