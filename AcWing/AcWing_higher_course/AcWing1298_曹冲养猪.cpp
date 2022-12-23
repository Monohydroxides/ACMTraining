#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 12;
LL a[N], b[N];
LL n, ans, lcm_ = 1;

void exgcd(LL a, LL b, LL& x, LL& y){
    if(!b){
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    LL x0 = x, y0 = y;
    x = y0, y = x0 - a / b * y0;
    return;
}

LL cf(LL x, LL k, LL p){
    LL s = 0;
    while(k){
        if(k & 1)   (s += x) %= p;
        (x += x) %= p, k >>= 1;
    }
    return s;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i], lcm_ *= a[i];
    for(int i = 1; i <= n; ++i){
        LL x, y, M = lcm_ / a[i];
        exgcd(M, a[i], x, y);
        x = (x % a[i] + a[i]) % a[i], (ans += cf(cf(b[i], M, lcm_), x, lcm_)) %= lcm_;
    }
    cout << ans << endl;
    return 0;
}
