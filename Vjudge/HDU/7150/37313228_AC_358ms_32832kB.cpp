#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
const int A = 1 << 0, B = 1 << 1, C = 1 << 2, D = 1 << 3;

int n, q;
int h[N], e[2 * N], ne[2 * N], idx;

int dep[N], sz[N], fa[N], son[N];
int id[N], top[N], cnt;

struct node{
    int l, r;
    int val1, val2, lazy;
}tr[N * 4];

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
    id[u]=++cnt, top[u]=father;
    if(!son[u]) return;
    dfs2(son[u], father);
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa[u] || j==son[u])   continue;
        dfs2(j, j);
    }
}

void pushup(int u){
    tr[u].val1 = tr[u << 1].val1 & tr[u << 1 | 1].val1;
    tr[u].val2 = tr[u << 1].val2 | tr[u << 1 | 1].val2;
}

void pushdown(int u){
    if(tr[u].lazy & D){
        tr[u].lazy ^= D;
        tr[u << 1].val1 = tr[u << 1].val2 = 0;
        tr[u << 1 | 1].val1 = tr[u << 1 | 1].val2 = 0;
        tr[u << 1].lazy = tr[u << 1 | 1].lazy = D;
    }
    if(tr[u].lazy){
        tr[u << 1].val1 |= tr[u].lazy;
        tr[u << 1 | 1].val1 |= tr[u].lazy;
        tr[u << 1].val2 |= tr[u].lazy;
        tr[u << 1 | 1].val2 |= tr[u].lazy;
        tr[u << 1].lazy |= tr[u].lazy;
        tr[u << 1 | 1].lazy |= tr[u].lazy; 
        tr[u].lazy = 0;
    }
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, r};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void update(int u, int l, int r, int type){
    if(l <= tr[u].l && tr[u].r <= r){
        if(type == D){
            tr[u].val1 = tr[u].val2 = 0;
            tr[u].lazy = D;
        }else{
            tr[u].val1 |= type, tr[u].val2 |= type, tr[u].lazy |= type;
        }
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid)  update(u << 1, l, r, type);
    if(mid < r)   update(u << 1 | 1, l, r, type);
    pushup(u);
}

void update_path(int u, int v, int type){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]])   swap(u, v);
        update(1, id[top[u]], id[u], type);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    update(1, id[v], id[u], type);
}

void update_subtree(int u, int type){
    update(1, id[u], id[u] + sz[u] - 1, type);
}

int query(int u, int l, int r){
    if(tr[u].val1 == A + B + C){
        // cout << u << " satisfy" << endl;
        return tr[u].r - tr[u].l + 1;
    }
    if(l == r)  return 0;
    pushdown(u);
    int res = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if(tr[u << 1].val2 == A + B + C){
        res += query(u << 1, l, mid);
    }
    if(tr[u << 1 | 1].val2 == A + B + C){
        res += query(u << 1 | 1, mid + 1, r);
    }
    // cout << "qry: " << u << " " << res << endl;
    return res;
}

void printSegtree(int u, int l, int r){
    if(!tr[u].l || !tr[u].r)   return;
    printf("node: %d, l: %d, r: %d, val1: %d, val2: %d\n", u, l, r, tr[u].val1, tr[u].val2);
    int mid = l + r >> 1;
    printSegtree(u << 1, l, mid), printSegtree(u << 1 | 1, mid + 1, r);
}

void work(){
    cin >> n >> q;
    idx = 0;
    for(int i = 1; i <= n; ++i) h[i] = -1;
    for(int i = 2; i <= n; ++i){
        int x;
        cin >> x;
        add(i, x), add(x, i);
    }
    dfs1(1, -1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    while(q--){
        int sza, szb, szc;
        cin >> sza >> szb >> szc;
        for(int i = 1; i <= sza; ++i){
            int x;
            cin >> x;
            update_path(1, x, A);
        }
        for(int i = 1; i <= szb; ++i){
            int x;
            cin >> x;
            update_path(1, x, B);
        }
        for(int i = 1; i <= szc; ++i){
            int x;
            cin >> x;
            update_subtree(x, C);
        }
        // cout << id[1] << " " << id[n] << endl;
        cout << query(1, 1, n) << endl;
        // printSegtree(1, 1, n);
        update(1, 1, n, D);
    }
    return;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)  work();
    // system("pause");
    return 0;
}
/*
1
7 3
1 1 2 2 3 3
2 1 1
1 2
4
1
4 4 3
4 5 6 7
4 5 6 7
2 4 6
2 1 1
4 5
6
1
*/
