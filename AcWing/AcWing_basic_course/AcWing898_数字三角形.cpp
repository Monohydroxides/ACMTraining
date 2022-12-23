#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n;
int p[N][N];
int f[N][N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            scanf("%d", &p[i][j]);
        }
    }
    f[1][1] = p[1][1];
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            if(j == 1){
                f[i][j] = f[i - 1][j] + p[i][j];
                continue;
            } else if(j == i){
                f[i][j] = f[i - 1][j - 1] + p[i][j];
                continue;
            }
            int t = max(f[i - 1][j], f[i - 1][j - 1]);
            f[i][j] = t + p[i][j];
        }
    }
    int res = -0x3f3f3f3f;
    for(int j = 1; j <= n; ++j){
        res = max(res, f[n][j]);
    }
    cout << res << endl;
    return 0;
}
