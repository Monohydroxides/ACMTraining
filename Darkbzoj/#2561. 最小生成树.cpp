#include <bits/stdc++.h>
using namespace std;

const int V = 200010, E = 4000010;
template <typename T> 
class Flow {
    public:
        int s, t;
        int h[V], e[E], ne[E], dis[V], cur[V], vtot, eid;
        T cap[E];

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
        
        void addEdge (int a, int b, T c, T d = 0) {
            add(a, b, c);
            add(b, a, d);
        }

        T dinic () {
            T flow = 0;
            while (bfs()) flow += dfs(s, numeric_limits<T>::max());
            return flow;
        }
};

Flow<int> g;

const int N = 200010;

int n, m, s, t, l;
array<int, 3> e[N];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    cin >> s >> t >> l;
    g.init(s, t, n);
    for (int i = 1; i <= m; i++)
        if (e[i][2] < l)
            g.addEdge(e[i][0], e[i][1], 1, 1);
    int ans1 =  g.dinic();

    g.init(s, t, n);
    for (int i = 1; i <= m; i++)
        if (e[i][2] > l)
            g.addEdge(e[i][0], e[i][1], 1, 1);
    int ans2 = g.dinic();
    cout << ans1 + ans2 << '\n';
    return 0;
}