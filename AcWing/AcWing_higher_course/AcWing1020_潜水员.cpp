#include <bits/stdc++.h>
using namespace std;

const int N=1001;

int m,n,k;
int a[N],b[N],c[N];
int f[30][80];

int main(){
    cin >> m >> n >> k;
    for(int i=1;i<=k;++i)   cin >> a[i] >> b[i] >> c[i];
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=k;++i){
        for(int j=m;j>=0;--j){
            for(int k=n;k>=0;--k){
                f[j][k]=min(f[j][k],f[max(0,j-a[i])][max(0,k-b[i])]+c[i]);                
            }
        }
    }
    cout << f[m][n] << endl;
    return 0;
}
