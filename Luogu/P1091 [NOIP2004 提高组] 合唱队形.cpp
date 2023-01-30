#include <bits/stdc++.h>

using namespace std;

int n;
int a[110];
int f[110], g[110];
int res = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], f[i] = g[i] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            if(a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
    }
    for(int i = n; i >= 1; --i){
        for(int j = n; j > i; --j){
            if(a[j] < a[i]) g[i] = max(g[i], g[j] + 1);
        }
    }
    for(int i = 1; i <= n; ++i){
        res = max(res, f[i] + g[i] - 1);
    }
    cout << n - res << endl;
    return 0;
}