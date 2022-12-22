#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, q;

int e[N], ne[N], h[N], idx;

int fa[N], dep[N], sz[N], son[N];
int id[N], top[N], cnt;

struct tree{
    int l, r, st, sum;
}tr[N * 4];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int father, int depth){
    fa[u] = father, dep[u] = depth, sz[u] = 1;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        dfs1(j, u, depth + 1);
        sz[u] += sz[j];
        if(sz[son[u]] < sz[j])	son[u] = j;
    }
}

void dfs2(int u, int tp){
    id[u] = ++ cnt, top[u] = tp;
    if(!son[u])	return;
    dfs2(son[u], tp);
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == son[u])	continue;
        dfs2(j, j);
    }
}

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
    auto& root = tr[u], & left = tr[u << 1], & right = tr[u << 1 | 1];
    // cout << tr[u].st << endl;
    if(root.st != -1){
        left.sum = (left.r - left.l + 1) * root.st;
        right.sum = (right.r - right.l + 1) * root.st;
        left.st = right.st = root.st;
        root.st = -1;
    }
}

void build(int u, int l, int r){
    if(l == r){
        tr[u].l = l, tr[u].r = r, tr[u].sum = 0, tr[u].st = -1;
        return;
    }
    tr[u].l = l, tr[u].r = r, tr[u].st = -1, tr[u].sum = 0;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    return;
}

void update(int u, int l, int r, int k){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum = k * (tr[u].r -  tr[u].l + 1);
        tr[u].st  = k;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid)	update(u << 1, l, r, k);
    if(mid < r)		update(u << 1 | 1, l, r, k);
    pushup(u);
}

void update_patch(int u, int v, int k){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]])	swap(u, v);
        update(1, id[top[u]], id[u], k);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v])	swap(u, v);
    update(1, id[v], id[u], k);
}

void update_tree(int u, int k){
    update(1, id[u], id[u] + sz[u] - 1, k);
}

int main(){
    cin.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i=2;i<=n;++i){
        int x;
        cin >> x;
        x++;
        add(x, i);
    }
    dfs1(1, -1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    cin >> q;
    while(q--){
        int x;
        string op;
        cin >> op >> x;
        ++x;
        if(op == "install"){
            int before = tr[1].sum;
            update_patch(1, x, 1);
            cout << tr[1].sum - before << endl;
        }else{
            int before = tr[1].sum;
            update_tree(x, 0);
            cout << before - tr[1].sum << endl;
        }
    }
    return 0;
}