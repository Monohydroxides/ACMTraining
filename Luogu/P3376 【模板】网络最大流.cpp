#include <bits/stdc++.h>
using namespace std;

const int N = 210, M = 10010;

int n, m, s, t;

int h[N], cur[N], dis[N], e[M], ne[M], eid, vtot;
long long cap[M];

void add (int a, int b, int c) {
    e[eid] = b, ne[eid] = h[a], cap[eid] = c, h[a] = eid++;
}

bool bfs () {
    for (int i = 0; i <= vtot; i++) {
        dis[i] = 0;
        cur[i] = h[i];
    }
    queue<int> qu;
    qu.push(s);
    dis[s] = 1;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (cap[i] && !dis[v]) {
                dis[v] = dis[u] + 1;
                if (v == t) return true;
                qu.push(v);
            }
        }
    }
    return false;
}

long long dfs (int u, long long m) {
    if (u == t) return m;
    long long flow = 0;
    for (int i = cur[u]; ~i; cur[u] = i = ne[i]) {
        int v = e[i];
        if (cap[i] && dis[v] == dis[u] + 1) {
            long long f = dfs(v, min(m, cap[i]));
            cap[i] -= f;
            cap[i ^ 1] += f;
            m -= f;
            flow += f;
            if (!m) break;
        }
    }
    if (!flow) dis[u] = -1;
    return flow;
}

long long dinic () {
    long long flow = 0;
    while (bfs()) flow += dfs(s, (1ll << 60));
    return flow;
}


int main () {
    memset(h, -1, sizeof h);
    cin >> n >> m >> s >> t;
    vtot = n;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    cout << dinic() << '\n';
    return 0;
}