#include <bits/stdc++.h>
using namespace std;

const int N = 50010, M = 200010;
template <typename T> 
class Flow {
    public:
    int s, t;
    int h[N], e[M], ne[M], dis[N], cur[N], vtot, eid;
    T cap[M];

    void add (int a, int b, T c) {
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

    T dfs (int u, T m) {
        if (u == t) return m;
        T flow = 0;
        for (int i = cur[u]; ~i; cur[u] = i = ne[i]) {
            int v = e[i];
            if (cap[i] && dis[v] == dis[u] + 1) {
                T f = dfs(v, min(m, cap[i]));
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

    void init (int _src, int _to, int _vtot) {
        s = _src;
        t = _to;
        vtot = _vtot;
        eid = 0;
        for (int i = 0; i <= vtot; i++) {
            h[i] = -1;
        }
    }
    
    void addEdge (int a, int b, int c) {
        add(a, b, c);
        add(b, a, 0);
    }

    T dinic () {
        T flow = 0;
        while (bfs()) flow += dfs(s, numeric_limits<T>::max());
        return flow;
    }
};

Flow<int> g;
array<array<int, 2>, N> par;
array<int, N> res;

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> par[i][0] >> par[i][1];
    }

    auto check = [&] (int ans) -> bool {
        g.init(n + m + 1, n + m + 2, n + m + 2);
        for (int i = 1; i <= m; i++) {  
            g.addEdge(n + m + 1, i, 1);
            res[i] = g.eid; 
            g.addEdge(i, par[i][0] + m, 1);
            g.addEdge(i, par[i][1] + m, 1);
        }
        for (int i = 1; i <= n; i++) {
            g.addEdge(i + m, n + m + 2, ans);
        }
        return g.dinic() == m;
    };

    int l = 1, r = m;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
    check(l);
    for (int i = 1; i <= m; i++) {
        if (g.cap[res[i]] == 0) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}