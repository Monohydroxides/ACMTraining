#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
vector<int> e[10010];
int aim[10010];

void dfs (int u, int cur) {
    if (aim[u] != cur) {
        ans++;
    }
    for (auto v : e[u]) {
        dfs(v, aim[u]);
    }
}

int main () {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        e[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> aim[i];
    }
    dfs(1, 0);
    cout << ans << '\n';
    return 0;
}