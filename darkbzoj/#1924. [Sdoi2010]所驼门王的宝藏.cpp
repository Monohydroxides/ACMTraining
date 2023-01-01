#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, R, C, tot;
int x[N], y[N], ty[N];
vector<int> e[N];
map< int, int > rv, cv;         // 行列辅助点的行号/列号 -> id
map< int, vector<int> > r, c;   // 点离散化
map< pair<int, int>, int > id;  // (x, y) 点的 id

int dfn[N], low[N], ins[N], bel[N], sz[N], dfncnt, scccnt;  // tarjan 用到的
stack<int> stk;
vector<int> scc[N]; // 用来存 scc

int dp[N];          // 反图拓扑序 dp

void tarjan (int u) {
    dfn[u] = low[u] = ++dfncnt;
    stk.push(u);
    ins[u] = 1;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        scccnt++;
        while (1) {
            int cur = stk.top();
            ins[cur] = 0;
            stk.pop();
            sz[scccnt] += (cur <= n);   // 不是辅助点才加 size
            scc[scccnt].push_back(cur);
            bel[cur] = scccnt;
            if (cur == u) break;
        }
    }
}

int main () {
    scanf("%d%d%d", &n, &R, &C);
    for (int i = 1; i <= n; i++) {
        int xi, yi, ti;
        scanf("%d%d%d", &xi, &yi, &ti);
        x[i] = xi, y[i] = yi, ty[i] = ti;
        r[xi].push_back(i);
        c[yi].push_back(i);
        id[{xi, yi}] = i;
    }
    tot = n;
    for (int i = 1; i <= n; i++) {
        if (ty[i] == 1) {
            if (!rv.count(x[i])) {  // 没有辅助点就加一个
                rv[x[i]] = ++tot;
                for (auto tmp : r[x[i]]) e[tot].push_back(tmp);
            }
            e[i].push_back(rv[x[i]]);
        } else if (ty[i] == 2) {
            if (!cv.count(y[i])) {
                cv[y[i]] = ++tot;
                for (auto tmp : c[y[i]]) e[tot].push_back(tmp);
            }
            e[i].push_back(cv[y[i]]);
        } else if (ty[i] == 3) {
            for (int dx = -1; dx <= 1; dx++) {  // 对于这种情况，直接遍历周围的八个点
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    if (!id.count({x[i] + dx, y[i] + dy})) continue;    // 没有点就不加边
                    e[i].push_back(id[{x[i] + dx, y[i] + dy}]);
                }
            }
        }
    }

    for (int i = 1; i <= tot; i++) if (!dfn[i]) tarjan(i);

    int ans = 0;
    for (int i = 1; i <= scccnt; i++) {
        for (auto u : scc[i]) {
            for (auto v : e[u]) {
                if (bel[v] == i) continue;
                dp[i] = max(dp[i], dp[bel[v]]);
            }
        }
        dp[i] += sz[i];
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}