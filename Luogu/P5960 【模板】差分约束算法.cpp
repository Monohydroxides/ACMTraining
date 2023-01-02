#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> x;
vector<array<int, 3>> e;

int main () {
    cin >> n >> m;
    x.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;         // xa <= xb + c
        e.push_back({a, b, c});
    }
    for (int i = 1; i <= n; i++) {
        e.push_back({0, i, 0});     // 建虚源点保证为正
    }
    for (int i = 0; i <= n; i++) {  // bellman ford
        for (auto [u, v, w] : e) {
            x[u] = min(x[u], x[v] + w);
        }
    }
    for (auto [u, v, w] : e) {      // 判断是否无解
        if (x[u] > x[v] + w) {
            cout << "NO\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {  // 输出与虚拟源点的差，让答案恒为正
        cout << x[i] - x[0] << ' ';
    }
    return 0;
}
