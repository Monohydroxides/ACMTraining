#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

double dist[N];
bool st[N];
double g[N][N];
int n, m, S, T;
void dijkstra () {
    dist[S] = 1;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if((!st[j]) && (t == -1 || dist[t] < dist[j]))
            t = j;
        }
        st[t] = true;
        for(int j = 1; j <= n; ++j){
            dist[j] = max(dist[j], dist[t] * g[t][j]);
        }
    }
}
int main () {
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        double z = (100.0 - c) / 100;
        g[a][b] = g[b][a] = max(g[a][b], z);
    }
    cin >> S >> T;
    dijkstra();
    cout << fixed << setprecision(8) << 100.0 / dist[T] << '\n';
}