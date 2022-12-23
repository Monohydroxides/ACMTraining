#include <bits/stdc++.h>
using namespace std;

#define int long long

int exgcd(int a, int b, int& x, int& y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

signed main(){
    int x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    int p, k;
    int d = exgcd(m - n, l, p, k);
    if((y - x) % d != 0){
        cout << "Impossible" << endl;
        return 0;
    }
    p = (y - x) / d * p;
    int t = abs(l / d);
    cout << ((p % t) + t) % t << endl;
    return 0;
}
