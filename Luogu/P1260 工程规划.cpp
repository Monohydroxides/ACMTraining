#include <bits/stdc++.h>
using namespace std;

int n, m;
int x[5010];
vector<array<int, 3>> e;

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({v, u, w});
    }
    for (int i = 1; i <= n; i++) {
        e.push_back({i, 0, 0});
    }
    for (int i = 1; i <= n; i++) {
        for (auto [u, v, w] : e) {
            x[v] = min(x[v], x[u] + w);
        }
    }
    for (auto [u, v, w] : e) {
        if (x[v] > x[u] + w) {
            cout << "NO SOLUTION\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << x[i] - x[0] << '\n';
    }
    return 0;
}