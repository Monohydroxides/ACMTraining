#include <bits/stdc++.h>
using namespace std;

int k;

int main(){
    cin >> k;
    int n, a[110], f[110], g[110], res;
    for(int i = 1; i <= k; ++i){
        res = 0;
        scanf("%d", &n);
        for(int j = 1; j <= n; ++j)  scanf("%d", &a[j]), f[j] = g[j] = 1;
        for(int j = 1; j <= n; ++j){
            for(int p = 1; p < j; ++p){
                if(a[j] > a[p]) f[j] = max(f[j], f[p] + 1);
            }
        }
        for(int j = n; j >= 1; --j){
            for(int p = n; p > j; --p){
                if(a[p] < a[j]) g[j] = max(g[j], g[p] + 1);
            }
        }
        for(int p = 1; p <= n; ++p){
            res = max(res, max(f[p], g[p]));
        }
        cout << res << endl;
    }

    return 0;
}
