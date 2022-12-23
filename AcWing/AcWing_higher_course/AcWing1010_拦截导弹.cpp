#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n = 1;
int a[N], f[N], g[N];

int main(){
    while(cin >> a[n])  f[n] = 1, ++n;
    n--;
    int res = 0;
    for(int i = 1; i <= n; ++i){
        int r = upper_bound(f + 1, f + 1 + res, a[i], greater<int>()) - f;
        res = max(res, r);
        f[r] = a[i];
    }
    cout << res << endl;
    res = 0;
    for(int i = 1; i <= n; ++i){
        int r = lower_bound(g + 1, g + 1 + res, a[i]) - g;
        res = max(res, r);
        g[r] = a[i];
    }
    cout << res << endl;
    return 0;
}
