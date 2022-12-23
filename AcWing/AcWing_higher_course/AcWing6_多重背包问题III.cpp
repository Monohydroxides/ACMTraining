#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int f[20010], g[20010], q[20010];

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        int v,w,s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f);
        for(int j=0;j<v;++j){
            int hh=0,tt=-1;
            for(int k=j;k<=m;k+=v){
                while(hh<=tt && (k-q[hh])/v>s) ++hh;
                if(hh<=tt)  f[k]=max(f[k],g[q[hh]]+(k-q[hh])/v*w);
                while(hh<=tt && g[q[tt]]-((q[tt])/v*w)<=g[k]-((k)/v*w)) --tt;
                q[++tt]=k;
            }
        }
    }
    cout << f[m] << endl;
}

