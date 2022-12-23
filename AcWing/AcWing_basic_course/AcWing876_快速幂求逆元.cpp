#include <bits/stdc++.h>
using namespace std;

int n;

int qmi(int a, int b, int p){
    int res = 1 % p;
    while(b){
        if(b & 1){
            res = (long long)res * a % p;
        }
        a = (long long)a * a % p;
        b >>= 1; 
    }
    return res;
}

int main(){
    cin >> n;
    int a, p;
    while(n--){
        cin >> a >> p;
        int res = qmi(a, p - 2, p);
        if(!res || a % p == 0)    cout << "impossible" << endl;
        else    cout << res << endl;
    }
    return 0;
}
