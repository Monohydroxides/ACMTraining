#include <bits/stdc++.h>
using namespace std;

int n;
int path[10];
int vis[10];

void dfs(int u){
    if (u == n){
        for(int i = 0; i < n; ++i){
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            path[u] = i;
            vis[i] = 1;
            dfs(u + 1);
            vis[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    dfs(0);
    return 0;
}
