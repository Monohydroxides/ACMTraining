#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;

LL exgcd(LL a, LL b, LL &x, LL &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    cin >> n;
    LL m2, a2, m1, a1;
    cin >> a1 >> m1;
    for(int i = 1; i < n; ++i){
        cin >> a2 >> m2;
        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        if((m2 - m1) % d)   {cout << -1 << endl; return 0;}
        k1 *= (m2 - m1) / d;
        k1 = (k1 % abs(a2 / d) + abs(a2 / d)) % abs(a2 / d);
        m1 = k1 * a1 + m1;
        a1 = abs(a1 / d * a2);
    }
    cout << m1 << endl;
    return 0;
}

