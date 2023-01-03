#include <bits/stdc++.h>
using namespace std;

const int N = 2010, M = 100010;

int n, k, s, t;
int h[N], dis[N], cur[N], e[M], ne[M], eid, vtot;
long long cap[M];

int tot, ccnt;
array<int, 3> used[M];
vector<int> ans[N];

void add (int a, int b, int c) {
    e[eid] = b, ne[eid] = h[a], cap[eid] = c, h[a] = eid++;
}

bool bfs () {
    for (int i = 0; i <= vtot; i++) {
        cur[i] = h[i];
        dis[i] = 0;
    }
    queue<int> qu;
    qu.push(s);
    dis[s] = 1;
    while (qu.size()) {
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
    cin >> k >> n;
    s = n + k + 1;
    t = n + k + 2;
    vtot = n + k + 2;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        add(s, i, x);
        add(i, s, 0);
        tot += x;
    }
    for (int i = 1; i <= n; i++) {
        add(i + k, t, 1);
        add(t, i + k, 0);
        int p;
        cin >> p;
        for (int j = 1; j <= p; j++) {
            int ty;
            cin >> ty;
            used[++ccnt] = {eid, ty, i};
            add(ty, i + k, 1);
            add(i + k, ty, 0);
        }
    }
    if (tot != dinic()) {
        cout << "No Solution!\n";
        return 0;
    }
    for (int i = 1; i <= ccnt; i++) {
        if (cap[used[i][0]] == 0) {
            ans[used[i][1]].push_back(used[i][2]);
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << i << ": ";
        for (auto j : ans[i]) {
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}