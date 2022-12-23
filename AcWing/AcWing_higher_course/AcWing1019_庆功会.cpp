#include <bits/stdc++.h>
using namespace std;

const int N=5001;

int n,m;
int cnt;
int v[N],w[N];
int f[6001];

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        int a,b,c;
        cin >> a >> b >> c;
        int k=1;
        while(c-k>=0){
            v[++cnt]=a*k,w[cnt]=b*k;
            c-=k;
            k<<=1;
        }
        if(c){
            v[++cnt]=a*c,w[cnt]=b*c;
        }
    }
    for(int i=1;i<=cnt;++i){
        for(int j=m;j>=v[i];--j){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
