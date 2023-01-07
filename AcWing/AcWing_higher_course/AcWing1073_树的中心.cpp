#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10, inf = 1e9;

int n, res = (1 << 30);

int h[N], e[M], ne[M], wi[M], eid;

int dst[N][2], fi[N], fa[N];

void add (int a, int b, int c) {
    e[eid] = b, ne[eid] = h[a], wi[eid] = c, h[a] = eid++;
}

int dfs1 (int u, int father) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == father) {
            continue; 
        }
        fa[v] = wi[i];
        int ans = dfs1(v, u) + wi[i];
        if (ans >= dst[u][0]) {
            dst[u][1] = dst[u][0];
            dst[u][0] = ans;
            fi[u] = v;
        } else if (ans >= dst[u][1]) {
            dst[u][1] = ans;
        }
    }
    return dst[u][0];
}

void dfs2 (int u, int father) {
    int tot = fa[u];
    if (father > 0) {
        if (fi[father] == u) {
            tot += dst[father][1];
        } else {
            tot += dst[father][0];
        }
    } else {
        tot = dst[u][0] + dst[u][1];
    }
    if (father > 0 && tot >= dst[u][0]) {
        fi[u] = father;
        dst[u][1] = dst[u][0];
        dst[u][0] = tot;
    } else if (father > 0 && tot >= dst[u][1]) {
        dst[u][1] = tot;
    }
    res = min({res, dst[u][0] > 0? dst[u][0]: inf});
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == father) continue;
        dfs2(v, u);
    }
}

int main () {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    cout << res << '\n';
    return 0;
}