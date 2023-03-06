#include <bits/stdc++.h>
using namespace std;

const int N = 210;

int n, m, k;
int g[N][N];

void floyd(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main(){
    memset(g, 0x3f, sizeof g);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) g[i][i] = 0;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    floyd();
    for(int i = 1; i <= k; ++i){
        int a, b;
        cin >> a >> b;
        if(g[a][b] >= 0x3f3f3f3f / 2){
            puts("impossible");
        }else{
            printf("%d\n", g[a][b]);
        }
    }
    return 0;
}