#include <bits/stdc++.h>
using namespace std;

const int N = 510;

const int V = 10010, E = 100010;
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

int n, ans;
int a[N], dp[N];
Flow<int> g;

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    if (ans == 1) {
		cout << n << '\n';
		sort(a + 1, a + 1 + n);
		int t = unique(a + 1, a + 1 + n) - a - 1;
		cout << t << '\n';
		return 0;
	}
    int s = 2 * n + 1, t = 2 * n + 2;
    
    g.init(s, t, t);
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1)
            g.addEdge(s, i, n);
        else if (dp[i] == ans)
            g.addEdge(i + n, t, n);
        g.addEdge(i, i + n, 1);
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[j] >= a[i] && dp[j] == dp[i] + 1)
                g.addEdge(i + n, j, 1);
    cout << g.dinic() << '\n';

    g.init(s, t, t);
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1)
            g.addEdge(s, i, n);
        else if (dp[i] == ans)
            g.addEdge(i + n, t, n);
        if ((i != 1 && i != n) || ans == 1) g.addEdge(i, i + n, 1);
        else g.addEdge(i, i + n, n);
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[j] >= a[i] && dp[j] == dp[i] + 1)
                g.addEdge(i + n, j, 1);
    cout << g.dinic() << '\n';
    return 0;
}