#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, d;
int m1, m2;
int h[N], e[2 * N], ne[2 * N], idx;

int cr[N], nr[N];
int fa[N], sz[N], dep[N];
int tag1[N], tag2[N];
int res[N][3];

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1 (int u, int father, int depth) {
    sz[u] = 1, fa[u] = father, dep[u] = depth;
    cr[depth] = u;
    if (depth > d) {
        nr[u] = cr[depth - d];
    } else {
        nr[u] = 1;
    }
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == father) {
            continue;
        }
        dfs1(v, u, depth + 1);
    }
}

void dfs2 (int u, int father, int type) {
    int cur = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == father) {
            continue;
        }
        dfs2(v, u, type);
        if (type == 1) {
            cur |= tag1[v];
        } else {
            cur |= tag2[v];
        }
    }
    if (type == 1) {
        tag1[u] |= cur;
    } else {
        tag2[u] |= cur;
    }
}

void work () {
    cin >> n >> d;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs1(1, -1, 1);
    cin >> m1;
    for (int i = 1; i <= m1; ++i) {
        int x;
        cin >> x;
        tag1[x] = 1, tag2[nr[x]] = 1;
    }
    cin >> m2;
    for (int i = 1; i <= m2; ++i) {
        int x;
        cin >> x;
        tag2[x] = 1, tag1[nr[x]] = 1;
    }
    dfs2(1, -1, 1);
    dfs2(1, -1, 2);
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (tag1[i]) {
            ans += 2;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (tag2[i]) {
            ans += 2;
        }
    }
    cout << ans << '\n';
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T = 1;
    while (T--) {
        work();
    }
    return 0;
}