#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, k;
int h[N], e[N], ne[N], idx;
int fa[N], dep[N], id[N], nw[N], sz[N], cnt;
bool st[N];

struct tree {
    int l, r;
    int add, maxn;
} tr[N * 4];

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1 (int u, int father, int depth) {
    fa[u] = father, dep[u] = depth, sz[u] = 1;
    id[u] = ++cnt, nw[cnt] = dep[u];
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        dfs1(v, u, depth + 1);
        sz[u] += sz[v];
    }
}

void pushup (int u) {
    tr[u].maxn = max(tr[u << 1].maxn, tr[u << 1 | 1].maxn);
}

void pushdown(int u){
    tr[u << 1].maxn += tr[u].add;
    tr[u << 1 | 1].maxn += tr[u].add;
    tr[u << 1].add += tr[u].add;
    tr[u << 1 | 1].add += tr[u].add;
    tr[u].add = 0;
}

void build (int u, int l, int r){
    if (l == r) {
        tr[u] = {l, r, 0, nw[l]};
        return;
    } else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify (int u, int l, int r, int k) {
    if(l <= tr[u].l && r >= tr[u].r){
        tr[u].maxn += k;
        tr[u].add += k;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid)    modify(u << 1, l, r, k);
    if(mid < r)     modify(u << 1 | 1, l, r, k);
    pushup(u);
}

int query (int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r)    return tr[u].maxn;
    pushdown(u);
    int res = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid)    res += query(u << 1, l, r);
    if(mid < r)     res += query(u << 1 | 1, l, r);
    return res;
}

bool check (int val) {
    int opt = k;
    vector< pair<int, int> > ops;
    for (int i = n; i >= 1; --i) {
        if (st[i]) {
            continue;
        }
        int curnd = i;
        int curdep = query(1, id[curnd], id[curnd]);
        if (curdep <= val) {
            continue;
        }
        if (opt > 0) {
            while (curdep > val) {
                st[curnd] = 1;
                curnd = fa[curnd];
                curdep--;
            }
            ops.push_back({i, curdep});
            modify(1, id[i], id[i] + sz[i] - 1, -curdep);
            opt--;
        } else {
            for (int j = ops.size() - 1; j >= 0; --j) {
                modify(1, id[ops[j].first], id[ops[j].first] + sz[ops[j].first] - 1, ops[j].second);
            }
            return false;
        }
    }
    k = opt;
    return true;
}

void work () {
    cin >> n >> k;

    idx = 0;
    for (int i = 0; i <= n + 1; ++i) {
        h[i] = -1;
        fa[i] = 0, dep[i] = 0, id[i] = 0, nw[i] = 0, sz[i] = 0;
        st[i] = 0;
    }
    cnt = 0;

    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        add(x, i);
    }
    dfs1(1, -1, 0);
    build(1, 1, n);
    int l = 1, r = 1;
    for (int i = 1; i <= n; ++i) {
        r = max(r, dep[i]);
    }
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << "\n";
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}