#include <bits/stdc++.h>
using namespace std;

int n;
int a[110][110], f[110][110];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) cin >> a[i][j];
    for(int i = 1; i <= n; ++i) f[0][i] = f[i][0] = 0x3f3f3f3f;
    f[1][0] = f[0][1] = 0; 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
        }
    }
    cout << f[n][n] << endl;
    return 0;
}
