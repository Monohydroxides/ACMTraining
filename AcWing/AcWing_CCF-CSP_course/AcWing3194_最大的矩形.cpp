#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[1010], f[40010];

int res;

signed main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], f[a[i]] = 1;
    for(int i = 1; i <= 40000; ++i){
        if(!f[i])   continue;
        int len = 0, p = 0;
        for(int j = 1; j <= n; ++j){
            if(a[j] >= i)   p++;
            else    p = 0;
            len = max(len, p);
        }
        res = max(res, len * i);
    }
    cout << res << endl;
    return 0;
}
