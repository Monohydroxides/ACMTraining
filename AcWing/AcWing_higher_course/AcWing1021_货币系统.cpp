#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[16];
long long f[3001];

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i)   cin >> a[i];
    f[0]=1;
    for(int i=1;i<=n;++i){
        for(int j=a[i];j<=m;++j){
            f[j]+=f[j-a[i]];
        }
    }
    cout << f[m] << endl;
    return 0;
}
