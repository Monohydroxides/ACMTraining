#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, ans;
vector<int> e[N];
bool vis[N];

void dfs (int u) {
    vis[u] = 1;
    ans++;
    // cout << u << " ";
    if (ans >= 1e6) return;
    for (auto v : e[u]) {
        if (!vis[v]) {
            dfs(v);
            vis[v] = 0;
        }
    }
}

int main () {
    cin >> n >> m;   
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (auto v : e[1]) {
        memset(vis, 0, sizeof vis);
        vis[1] = 1;
        dfs(v);
    }
    cout << min(1000000, ans + 1) << '\n';
    return 0;
}