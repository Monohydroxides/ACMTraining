#include <bits/stdc++.h>
using namespace std;

int n, res;
int a[1010], f[1010], g[1010];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), f[i] = g[i] = 1;
    for(int i = 1; i <= n; ++i) for(int j = 1; j < i; ++j)  if(a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
    for(int i = n; i >= 1; --i) for(int j = n; j > i; --j)  if(a[j] < a[i]) g[i] = max(g[i], g[j] + 1);
    for(int i = 1; i <= n; ++i) res = max(res, f[i] + g[i] - 1);
    cout << res << endl;
    return 0;
}
