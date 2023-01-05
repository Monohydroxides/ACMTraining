#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int inf = 1e9;

int N, P, C;
map<int, int> cnt;

int h[810], e[3000], ne[3000], wi[3000], eid;

int dist[810];
bool vis[810];

void add (int a, int b, int c) {
    e[eid] = b, ne[eid] = h[a], wi[eid] = c, h[a] = eid++;
}

void dijkstra (int src) {
    for (int i = 1; i <= P; i++) dist[i] = inf, vis[i] = 0;
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    while (pq.size()) {
        auto cur = pq.top(); pq.pop();
        int u = cur.second, w = cur.first;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > w + wi[i]) {
                dist[v] = w + wi[i];
                pq.push({dist[v], v});
            }
        }
    }
}

int main () {
    cin >> N >> P >> C;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= C; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    long long res = (1ll << 60);
    for (int i = 1; i <= P; i++) {
        dijkstra(i);
        long long ans = 0;
        int flg = 1;
        for (auto [k, v] : cnt) {
            if (dist[k] == inf) {
                flg = 0;
                break;
            } else {
                ans += (long long) dist[k] * v;
            }
        }
        if (!flg) continue;
        res = min(res, ans);
    }
    cout << res << '\n';
    return 0;
}
