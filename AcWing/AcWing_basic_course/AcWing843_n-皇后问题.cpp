#include <bits/stdc++.h>
using namespace std;
const int N = 10;
char g[N][N];
bool col[N], dig[N * 2], udig[N * 2];
int n;

void dfs(int u){
    if(u == n){
        for(int i = 0; i <= n; ++i){
            printf("%s\n", g[i]);
        }
        return;
    }

    for(int i = 0; i < n; ++i){
        if(!col[i] && !dig[u + i] && !udig[n - u + i]){
            g[u][i] = 'Q';
            col[i] = dig[u + i] = udig[n - u + i] = true;
            dfs(u + 1);
            g[u][i] = '.';
            col[i] = dig[u + i] = udig[n - u + i] = false;
        }
    }
}

int main(){
    cin >> n; 
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            g[i][j] = '.';
    dfs(0);
    return 0;
}















