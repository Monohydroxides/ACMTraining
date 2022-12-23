#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[101];
int f[2][101][10001];

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i)   cin >> a[i];
    f[0][0][0]=1,f[1][0][0]=0;
    for(int i=1;i<=n;++i){
        for(int k=0;k<=m;++k){
            if(k>=a[i]) f[1][i][k]=f[1][i-1][k-a[i]]+f[0][i-1][k-a[i]];
            f[0][i][k]=f[1][i-1][k]+f[0][i-1][k];
        }
    }
    // for(int i=0;i<=n;++i){
    //     for(int j=0;j<=m;++j){
    //         cout << f[0][i][j] << " " << f[1][i][j] << "     ";
    //     }
    //     cout << endl;
    // }
    cout << f[0][n][m]+f[1][n][m] << endl;
    return 0;
}
