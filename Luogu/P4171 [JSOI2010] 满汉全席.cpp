#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int n, m;
vector<int> e[N];

int dfn[N], low[N], bel[N], dfncnt, scccnt;
bool ins[N];
stack<int> stk;

void dfs (int u) {
    dfn[u] = low[u] = ++dfncnt;
    ins[u] = 1;
    stk.push(u);
    for (auto v : e[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        scccnt++;
        while (1) {
            int cur = stk.top();
            stk.pop();
            ins[cur] = 0;
            bel[cur] = scccnt;
            if (cur == u) break;
        }
    }
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        char str1, str2;
        int a, b;
        for (int i = 1; i <= m; i++) {
            cin >> str1 >> a >> str2 >> b;
            // cout << str1 << " " << a << " " << str2 << " " << b << '\n';
            int p = a - 1;
            int q = b - 1;
            p = p * 2 + (str1 == 'h');
            q = q * 2 + (str2 == 'h');
            e[p ^ 1].push_back(q);
            e[q ^ 1].push_back(p);
        }
        for (int i = 0; i < n * 2; i++) {
            if (!dfn[i]) {
                dfs(i);
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout << bel[i * 2] << " " << bel[i * 2 + 1] << '\n';
        // }
        int flg = 0;
        for (int i = 0; i < n; i++) {
            if (bel[i * 2] == bel[i * 2 + 1]) {
                cout << "BAD\n";
                flg = 1;
                break;
            }
        }
        if (!flg) {
            cout << "GOOD\n";    
        }

        for (int i = 0; i < 2 * n; i++) e[i].clear(), dfn[i] = low[i] = bel[i] = ins[i] = 0;
        while (stk.size())  stk.pop();
        dfncnt = scccnt = 0;
    }
    return 0;
}