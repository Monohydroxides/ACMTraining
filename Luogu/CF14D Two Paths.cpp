#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
int tag[210];
int dep[210];
vector<pair<int, int>> e;
vector<int> es[210];

void dfs (int u, int depth, int father, int ap) {
    dep[u] = depth;
    for (auto v : es[u]) {
        if (v == father || v == ap) continue;
        dfs(v, depth + 1, u, ap);
    }
}

int work (int u, int ap) {
    memset(dep, 0, sizeof dep);
    dfs(u, 1, -1, ap);
    int mx = 0, mxl = 0;
    for (int i = 1; i <= n; i++) {
        if (dep[i] > mx) {
            mx = dep[i];
            mxl = i;
        }
    }
    dfs(mxl, 1, -1, ap);
    mx = 0;
    for (int i = 1; i <= n; i++) {
        if (dep[i] > mx) {
            mx = dep[i] - 1;
        }
    }
    return mx;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e.push_back({u, v});
        es[u].push_back(v);
        es[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        tag[i] = 1;
        ans = max(ans, work(e[i].first, e[i].second) * work(e[i].second, e[i].first));
        tag[i] = 0;
    }
    cout << ans << '\n';
    return 0;
}