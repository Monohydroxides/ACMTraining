#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, q;
int h[N], e[N], ne[N], idx;

int w[N];
int dep[N], sz[N], fa[N], son[N];
int id[N], nw[N], top[N], cnt;
map<pair<int, int>, int> mp;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int father, int depth){
    fa[u]=father, sz[u]=1, dep[u]=depth;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==father)   continue;
        dfs1(j,u,depth+1);
        sz[u]+=sz[j];
        if(sz[son[u]]<sz[j])    son[u]=j;
    }
}

void dfs2(int u, int father){
    id[u]=++cnt, nw[cnt]=w[u], top[u]=father;
    if(!son[u]) return;
    dfs2(son[u], father);
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa[u] || j==son[u])   continue;
        dfs2(j, j);
    }
}

int lca(int a, int b){
    while(top[a] != top[b]){
        if(dep[top[a]] < dep[top[b]])	swap(a, b);
        a = fa[top[a]];
    }
    return dep[a] < dep[b]? a: b;
}

void work(){
    int k;
    cin >> k;
    vector<int> qry;
    for(int i = 1; i <= k; ++i){
        int x; 
        cin >> x;
        qry.push_back(x);
    }
    int f = 2;
    
    cout << "YES" << endl;
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n - 1; ++i){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs1(1, -1, 1);
    dfs2(1, 1);
    cin >> q;
    while(q--)  work();
    return 0;
}