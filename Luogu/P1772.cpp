#include <bits/stdc++.h>
using namespace std;

const int N = 25, M = 410;

int n, m, k, p, d;
int h[N], ne[M], e[M], wit[M], idx;
int tag[110][N];
long long cstij[110][110];
int cant[N];
long long dp[110];
int vis[N];
long long dist[N];
int que[10010];

void add (int a, int b, int c) {
    e[++idx] = b;
    ne[idx] = h[a];
    wit[idx] = c;
    h[a] = idx;
}

void dijkstra () {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; ++i) {
        dist[i] = 1e14;
    }
    dist[1] = 0;
    priority_queue< pair<long long, int> , vector< pair<long long, int> >, greater< pair<long long, int> > > q;
    q.push({0, 1});
    while (q.size()) {
        auto cur = q.top();
        q.pop();
        if (vis[cur.second]) {
            continue;
        }
        vis[cur.second] = 1;
        for (int i = h[cur.second]; i; i = ne[i]) {
            int v = e[i];
            if (cant[v]) {
                continue;
            }
            if (dist[v] > dist[cur.second] + wit[i]) {
                dist[v] = dist[cur.second] + wit[i];
                q.push({dist[v], v});
            }
        }
    }
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> p;
    for (int i = 1; i <= p; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    cin >> d;
    for (int i = 1; i <= d; ++i) {
        int x, st, ed;
        cin >> x >> st >> ed;
        for (int j = st; j <= ed; ++j) {
            tag[j][x] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        memset(cant, 0, sizeof cant);
        for (int j = i; j <= n; ++j) {
            for (int k = 1; k <= m; ++k) {
                if (tag[j][k]) {
                    cant[k] = 1;
                }
            } 
            dijkstra();
            cstij[i][j] = dist[m];
            // cout << i << " " << j << " " << cstij[i][j] << "\n";
            // cout << i << " " << j << " " << cstij[i][j] << '\n';
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = cstij[1][i] * i;
        for (int j = 1; j < i; ++j) {
            dp[i] = min(dp[i], dp[j] + (long long) cstij[j + 1][i] * (i - j) + k);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}