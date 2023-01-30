#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 1010, M = 2010;

int n;
int head[N], nxt[M], to[M], eid;
int fa[N], dep[N];
bool vis[N];
priority_queue<pii> pq;

void add (int a, int b) {
    to[eid] = b, nxt[eid] = head[a], head[a] = eid++;
}

void dfs1 (int u, int father, int depth) {
    dep[u] = depth;
    pq.push({dep[u], u});
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        if (v == father) continue;
        dfs1(v, u, depth + 1);
    }
}

void dfs2 (int u, int father, int depth) {
    if (depth > 2) return;
    vis[u] = 1;
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        if (v == father) continue;
        dfs2(v, u, depth + 1);
    }
}

int main () {
    memset(head, -1, sizeof head);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        add(x, i);
        add(i, x);
        fa[i] = x; 
    }
    dfs1(1, -1, 1);
    // for (int i = 1; i <= n; i++) cout << dep[i] << " ";
    // cout << '\n';
    int ans = 0;
    while (pq.size()) {
        auto cur = pq.top();
        pq.pop();
        if (vis[cur.second]) continue;
        if (fa[fa[cur.second]]) dfs2(fa[fa[cur.second]], -1, 0);
        else dfs2(1, -1, 0);
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
