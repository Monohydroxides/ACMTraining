#include <bits/stdc++.h>
using namespace std;

const int N = 310;

int n, m;
int g[N][N];
int f[N][N];
int dxy[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int dp(int x, int y){
    if(f[x][y] != -1)   return f[x][y];
    f[x][y] = 1;
    for(int i = 0; i < 4; ++i){
        int nx = x + dxy[i][0], ny = y + dxy[i][1];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && g[nx][ny] < g[x][y]){
            f[x][y] = max(f[x][y], dp(nx, ny) + 1);
        }
    }
    return f[x][y];
}

int main(){
    memset(f, -1, sizeof f);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> g[i][j];
    int res = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            res = max(res, dp(i, j));
    cout << res << endl;
    return 0;
}
