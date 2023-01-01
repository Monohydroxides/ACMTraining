#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m;
vector<int> e[N];

int dfn[N], low[N], cut[N], dfncnt, cccnt;
vector<int> cc[N];
stack<int> stk;

void tarjan (int u, int father) {
    dfn[u] = low[u] = ++dfncnt;
    stk.push(u);
    int ch = 0;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            tarjan(v, u);
            ch++;
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v]) {
                cut[u] = 1;
                cccnt++;
                cc[cccnt].push_back(u);
                while (1) {
                    int cur = stk.top();
                    cc[cccnt].push_back(cur);
                    stk.pop();
                    if (cur == v) break;
                }
            }
        } else if (v != father) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (ch < 2 && u == father) cut[u] = 0;
}

int main () {
    int Case = 0;
    while (cin >> m, m) {
        Case++;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            n = max({n, u, v});
        }
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                tarjan(i, i);
            }
        }
        cout << "Case " << Case << ": ";
        if (cccnt == 1) {
            int n = cc[1].size();
            cout << 2 << " " << (long long) n * (n - 1) / 2 << '\n';
        } else {
            int res = 0;
            long long tot = 1;
            for (int i = 1; i <= cccnt; i++) {
                int ans = 0;
                for (auto u : cc[i]) {
                    if (cut[u]) {
                        ans++;
                    }
                }
                if (ans == 1) {
                    res++;
                    tot = tot * (int) (cc[i].size() - 1);
                }
            }
            cout << res << " " << tot << '\n';
        }

        for (int i = 1; i <= 1000; i++) e[i].clear();
        for (int i = 1; i <= n; i++) {
            dfn[i] = low[i] = cut[i] = 0;
        }
        for (int i = 1; i <= cccnt; i++) cc[i].clear();
        dfncnt = cccnt = n = 0;
        while (!stk.empty()) stk.pop();
    }   
    return 0;
}
 