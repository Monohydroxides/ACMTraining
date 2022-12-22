#include <bits/stdc++.h>
using namespace std;

int m,k;
int cst[30], imp[30];
int f[30][30010];

int main(){
    cin >> m >> k;
    for(int i=1;i<=k;++i){
        int aa, bb;
        cin >> aa >> bb;
        cst[i]=aa, imp[i]=aa*bb;
    }
    for(int i=1;i<=k;++i){
        for(int j=0;j<=m;++j){
            f[i][j]=f[i-1][j];
            if(j>=cst[i])   f[i][j]=max(f[i][j],f[i-1][j-cst[i]]+imp[i]);   
        }
    }
    cout << f[k][m] << endl;
    return 0;
}