#include <bits/stdc++.h>
using namespace std;

const int N=1001;
int n,V;
int cnt;
int v[N*10],w[N*10],s[N*10];
int f[N];

int main(){
    cin >> n >> V;
    for(int i=1;i<=n;++i){
        int a,b,c;
        cin >> a >> b >> c;
        if(c<=0){
            v[++cnt]=a,w[cnt]=b,s[cnt]=c;
        }else{
            int k=1;
            while(c-k>=0){
                v[++cnt]=k*a,w[cnt]=k*b,s[cnt]=-1;
                c-=k;
                k<<=1;
            }
            if(c){
                v[++cnt]=c*a,w[cnt]=c*b,s[cnt]=-1;
            }
        }
    }
    for(int i=1;i<=cnt;++i){
        if(s[i]==-1){
            for(int j=V;j>=v[i];--j){
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }else if(s[i]==0){
            for(int j=v[i];j<=V;++j){
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }else{
            for(int k=0;k<=s[i];++k){
                for(int j=V;j>=k*v[i];--j){
                    f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
                }
            }
        }
    }
    cout << f[V] << endl;
    return 0;
}
