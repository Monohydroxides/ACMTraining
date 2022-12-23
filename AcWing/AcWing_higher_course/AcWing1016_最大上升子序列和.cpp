#include <bits/stdc++.h>
using namespace std;

int n, a[1010], f[1010];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), f[i] = a[i];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            if(a[j] < a[i]) f[i] = max(f[i], a[i] + f[j]);/*, cout << j << " " << i << " " << f[i] << endl;*/
        }
    }
    int res = 0;
    for(int i = 1; i <= n; ++i) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}
