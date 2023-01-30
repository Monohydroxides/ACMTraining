#include <bits/stdc++.h>
using namespace std;

int n, m;
int x[5010];
vector<array<int, 3>> e;

int main () {
    cin >> n >> m;
    for (int i = 1;  i <= m; i++) {
        int op, u, v, w;
        cin >> op;
        if (op == 1) {
            cin >> u >> v >> w;
            e.push_back({v, u, w});
        } else if (op == 2) {
            cin >> u >> v >> w;
            e.push_back({u, v, -w});
        } else if (op == 3) {
            cin >> u >> v;
            e.push_back({u, v, 0});
            e.push_back({v, u, 0});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto [u, v, w] : e) {
            x[v] = max(x[v], x[u] + w);
        }
    }
    for (auto [u, v, w] : e) {
        if (x[v] < x[u] + w) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}