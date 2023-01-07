#include <bits/stdc++.h>
using namespace std;

const int N = 110;

vector<int> e[N];
bool vis[N];

void dfs (int u) {
    vis[u] = 1;
    for (auto v : e[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            res++;
            dfs(i);
        }   
    }
    cout << res << '\n';
    return 0;
}
