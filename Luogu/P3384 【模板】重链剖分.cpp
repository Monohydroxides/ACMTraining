#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100010;

int n, m, r, p;

int h[N], e[2*N], ne[2*N], idx;

int w[N];
int dep[N], sz[N], fa[N], son[N];
int id[N], nw[N], top[N], cnt;

struct tree{
    int l, r;
    int add, sum;
}tr[N*4];

void add(int a, int b){
    e[idx]=b, ne[idx]=h[a], h[a]=idx++;
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

void pushup(int u){
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void pushdown(int u){
    tr[u << 1].sum += (tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1)) % p;
    tr[u << 1 | 1].sum += tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) % p;
    tr[u << 1].add += tr[u].add % p;
    tr[u << 1 | 1].add += tr[u].add % p;
    tr[u].add = 0;
}

void build(int u, int l, int r){
    if(l==r){
        tr[u] = {l,r,0,nw[r]};
        return;
    }else{
        tr[u]={l,r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void update(int u, int l, int r, int k){
    if(l <= tr[u].l && r >= tr[u].r){
        tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
        tr[u].add += k;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid)    update(u << 1, l, r, k);
    if(mid < r)     update(u << 1 | 1, l, r, k);
    pushup(u);
}

LL query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r)    return tr[u].sum;
    pushdown(u);
    LL res = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid)    res += query(u << 1, l, r) % p;
    if(mid < r)     res += query(u << 1 | 1, l, r) % p;
    return res % p;
}

void update_path(int u, int v, int k){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]])   swap(u, v);
        update(1, id[top[u]], id[u], k);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    update(1, id[v], id[u], k);
}

LL query_path(int u, int v){
    LL res = 0;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]])   swap(u, v);
        res += query(1, id[top[u]], id[u]) % p;
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    res += query(1, id[v], id[u]) % p;
    return res % p;
}

int main(){
    cin.tie(0);
    cin >> n >> m >> r >> p;
    memset(h, -1, sizeof h);
    for(int i=1;i<=n;++i)   cin >> w[i];
    for(int i=1;i<=n-1;++i){
        int aa, bb;
        cin >> aa >> bb;
        add(aa,bb), add(bb,aa);
    }
    dfs1(r,-1,1);
    dfs2(r,r);
    build(1,1,n);
    while(m--){
        int op, u, v, k;
        cin >> op;
        if(op==1){
            cin >> u >> v >> k;
            update_path(u, v, k);
        }else if(op==3){
            cin >> u >> k;
            update(1, id[u], id[u] + sz[u] - 1, k);
        }else if(op==2){
            cin >> u >> v;
            cout << query_path(u, v) << endl; 
        }else{
            cin >> u;
            cout << query(1, id[u], id[u] + sz[u] - 1) % p << endl;
        }
    }
    return 0;
}