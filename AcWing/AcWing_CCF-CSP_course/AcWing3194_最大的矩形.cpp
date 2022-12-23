#include <bits/stdc++.h>
using namespace std;

int n;
int a[1010], f[10010];

int res;

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], f[a[i]] = 1;
    for(int i = 1; i <= 10000; ++i){
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
