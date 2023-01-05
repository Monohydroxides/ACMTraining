#include <bits/stdc++.h>
using namespace std;

const int N = 2050;

int g[N][N];
int dist[N];
bool vis[N];

int gcd (int a, int b) {
    return b == 0? a: gcd(b, a % b);
}

void dijkstra () {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= 2021; i++) {
        int t = -1;
        for (int j = 1; j <= 2021; j++)
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        for (int j = 1; j <= 2021; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        vis[t] = true;
    }
}

int main () {
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= 2021; i++) {
        for (int j = max(0, i - 21); j <= min(2021, i + 21); j++) {
            g[i][j] = g[j][i] = i * j / gcd(i, j);
        }
    }
    dijkstra();
    cout << dist[2021] << '\n';
    return 0;
}