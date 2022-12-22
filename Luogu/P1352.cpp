#include <bits/stdc++.h>
using namespace std;

const int N = 6010;

int n, res;
int rot;
int h[N], e[N], ne[N], idx;
int w[N], indeg[N];
int f[N][2];

void add(int a, int b){
    e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

void dfs(int nd){
    f[nd][1]=w[nd];
    for(int i=h[nd];~i;i=ne[i]){
        dfs(e[i]);
        f[nd][0]+=max(f[e[i]][1],f[e[i]][0]);
        f[nd][1]+=f[e[i]][0];
    }
}

void work(){
    dfs(rot);
    res=max(f[rot][1], f[rot][0]);
}

int main(){
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;++i)   cin >> w[i];
    for(int i=1;i<=n-1;++i){
        int a, b;
        cin >> a >> b;
        add(b, a);
        indeg[a]++;
    }
    for(int i=1;i<=n;++i)   if(!indeg[i])   rot=i;
    work();
    cout << res << endl;
    return 0;
}