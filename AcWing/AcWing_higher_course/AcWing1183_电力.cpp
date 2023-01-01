#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n, m;
vector<int> e[N];

int dfn[N], low[N], dfncnt, cccnt, ans;
bool cut[N];

void tarjan (int u, int father) {
    dfn[u] = low[u] = ++dfncnt;
    int st = 0;
    for (auto v: e[u]) {
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min({low[u], low[v]});
            if (dfn[u] <= low[v]) {
                cut[u] = 1;
                st++;
            }
        } else if (v != father) {
            low[u] = min({low[u], dfn[v]});
        }
    }
    if (u != father) st++;
    ans = max(ans, st);
}

int main () {
    while (cin >> n >> m) {

        if (n == 0 && m == 0) {
            break;
        }

        if (!m) {
            cout << n - 1 << '\n';
            continue;
        }
        
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            u++, v++;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                cccnt++;
                tarjan(i, i);
            }
        }

        cout << ans + cccnt - 1 << '\n';

        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1; i <= n; i++) dfn[i] = low[i] = cut[i] = 0;
        dfncnt = cccnt = ans = 0;
    }
    return 0;
}