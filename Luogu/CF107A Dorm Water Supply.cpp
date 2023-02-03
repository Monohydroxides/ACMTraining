#include <bits/stdc++.h>
using namespace std;

int n, m;
int ind[1010], oud[1010];
vector<array<int, 2>> e[1010];

array<int, 2> dfs (int u, int f) {
    if (!e[u].size()) {
        return {u, f};
    }
    return dfs(e[u][0][0], min(f, e[u][0][1]));
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        ind[v]++;
        oud[u]++;
    }
    vector<array<int, 3>> ans;
    for (int i = 1; i <= n; i++) {
        if (!ind[i] && oud[i] == 1) {
            auto res = dfs(i, 1 << 30);
            ans.push_back({i, res[0], res[1]});
        }
    }
    cout << ans.size() << '\n';
    for (auto [u, v, w] : ans) {
        cout << u << " " << v << " " << w << "\n";
    }
    return 0;
}