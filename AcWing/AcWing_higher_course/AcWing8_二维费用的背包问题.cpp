#include <bits/stdc++.h>
using namespace std;

const int CST=1001;

int N,V,M;
int v[CST],m[CST],w[CST];
int f[CST][101][101];

int main(){
    cin >> N >> V >> M;
    for(int i=1;i<=N;++i){
        cin >> v[i] >> m[i] >> w[i];
    }
    for(int i=1;i<=N;++i){
        for(int j=0;j<=V;++j){
            for(int k=0;k<=M;++k){
                f[i][j][k]=max(f[i][j][k],f[i-1][j][k]);
                if(j>=v[i] && k>=m[i])  f[i][j][k]=max(f[i][j][k],f[i-1][j-v[i]][k-m[i]]+w[i]);
            }
        }
    }
    // for(int i=1;i<=N;++i){
    //     for(int j=1;j<=V;++j){
    //         for(int k=1;k<=M;++k){
    //             cout << f[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl << endl;
    // }
    cout << f[N][V][M] << endl;
    return 0;
}
