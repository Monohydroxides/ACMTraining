#include <bits/stdc++.h>
using namespace std;

int n,m,k;
pair<int,int> a[110];
int f[1010][510];

int main(){
    cin >> n >> m >> k;
    for(int i=1;i<=k;++i)   cin >> a[i].first >> a[i].second;
    for(int i=1;i<=k;++i){
        for(int j=n;j>=a[i].first;--j){
            for(int p=m;p>=a[i].second;--p){
                if(f[j][p]<f[j-a[i].first][p-a[i].second]+1){
                    f[j][p]=f[j-a[i].first][p-a[i].second]+1;
                }
            }
        }
    }
    int res=0, mhp=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<m;++j){
            if(res<f[i][j] || (res==f[i][j] && j<mhp)){
                res=max(res,f[i][j]);
                mhp=j;
            }
        }
    }
    cout << res << " " << m-mhp << endl;
    return 0;
}
