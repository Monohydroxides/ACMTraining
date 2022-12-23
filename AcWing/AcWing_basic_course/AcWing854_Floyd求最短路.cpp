#include <bits/stdc++.h>
using namespace std;

int n, m, p;
int g[205][205];

int main(){
    cin >> n >> m >> p;
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; ++i) g[i][i] = 0;
    int a, b, c;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for(int i = 1; i <= p; ++i){
        cin >> a >> b;
        if(g[a][b] > 0x3f3f3f3f / 2)    puts("impossible");
        else    cout << g[a][b] << endl;
    }
    return 0;
}
