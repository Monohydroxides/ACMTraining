#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n;

LL phi(LL x){
    LL res = x;
    for(LL i = 2; i * i <= x; ++i) {
        if(x % i == 0) res = res / i * (i - 1);
        while(x % i == 0) x /= i; 
    }
    if(x > 1) res = res / x * (x - 1);
    return res;
}

int main(){
    cin >> n;
    LL res = 0;
    LL i = 1;
    for(; i * i < n; ++i){
        // cout << i << " " << n % i << endl; 
        if(n % i == 0){
            res += i * phi(n / i);
            res += n / i * phi(i);
        }
    }
    if(i * i == n){
        res += i * phi(n / i);
    }
    cout << res << endl;
    return 0;
}
