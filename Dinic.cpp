#include <bits/stdc++.h>
using namespace std;

const int V = 210, E = 20010;
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

int main () {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    Flow<long long> g;
    g.init(s, t, n);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
    cout << g.dinic() << '\n';
    return 0;
}