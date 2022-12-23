#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long a, b, p;
    cin >> a >> b >> p;
    a = a % p;
    unsigned long long res = 0;
    for(; b; b >>= 1){
        if(b & 1){
            res += a;
            res = res % p;
        }
        a <<= 1;
        a = a % p;
    }
    cout << res % p << endl;
    return 0;
}
