#include <bits/stdc++.h>
using namespace std;

int n,m;
int w[20][20];
int f[15][20];
int path[20], cnt;

void dfs(int i, int j){
    if(i==0) return;
    for(int k=0;j+k<=m;++k){
        if (f[i-1][j+k]+w[i][k]==f[i][j]){
            path[++cnt]=k;
            dfs(i-1, j+k);
            return;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i)   for(int j=1;j<=m;++j)   cin >> w[i][j];
    for(int i=1;i<=n;++i){
        for(int j=0;j<=m;++j){
            f[i][j]=f[i-1][j];
            for(int k=0;k<=j;++k){
                if(f[i][j-k]<f[i-1][j]+w[i][k]){
                    f[i][j-k]=f[i-1][j]+w[i][k];
                }
            }
        }
    }
    dfs(n,0);
    // for(int i=1;i<=n;++i){
    //     for(int j=0;j<=m;++j){
    //         cout << f[i][j] << " "; 
    //     }
    //     cout << endl;
    // }
    cout << f[n][0] << endl;
    for(int i=n;i>=1;--i){
        cout << n-i+1 << " " << path[i] << endl;
    }
    return 0;
}
