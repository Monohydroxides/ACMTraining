#include <bits/stdc++.h>
using namespace std;

const int N = 210;

int n, m, k, r;
struct point {
    int x, y;
} p[N];
int h[N], e[N * N], ne[N * N], idx;
int dist[N][N];
int ans;

bool check (int x, int y) {
    return (long long) (p[x].x - p[y].x) * (p[x].x - p[y].x) + (long long) (p[x].y - p[y].y) * (p[x].y - p[y].y) <= (long long) r * r;
}

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs () {
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;
    queue< point > que;
    que.push({1, 0});
    while (que.size()) {
        auto fr = que.front();
        que.pop();
        for (int i = h[fr.x]; ~i; i = ne[i]) {
            int cst = fr.y;
            int v = e[i];
            if (v > n) {
                cst++;
            }
            if (cst <= k) {
                if (dist[v][cst] > dist[fr.x][fr.y] + 1) {
                    dist[v][cst] = dist[fr.x][fr.y] + 1;
                    que.push({v, cst});
                }
            }
        }
    }
    ans = n;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dist[2][i]);
    }
}

int main () {
    memset(h, -1, sizeof h);
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= n + m; i++) {
        cin >> p[i].x >> p[i].y;
    }
    for (int i = 1; i <= n + m; i++) {
        for (int j = i + 1; j <= n + m; j++) {
            if (check(i, j)) {
                add(i, j), add(j, i);
            }
        }
    }
    bfs();
    cout << ans - 1 << '\n';
    return 0;
}