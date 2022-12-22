#include <bits/stdc++.h>
using namespace std;

const int N = 500010;

int n;
int ori[N];
int e[2 * N], ne[2 * N], w[2 * N], h[N], idx;

int dep[N], fa[N];

double dp[N];

void add (int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dfs1 (int u, int depth, int father) {
    dep[u] = depth, fa[u] = father;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == father) {
            continue;
        }
        dfs1(v, depth + 1, u);
        dp[u] = dp[u] + dp[v] * ((double) w[i] / (double) 100.0) - dp[u] * dp[v] * ((double) w[i] / (double) 100.0);
    }
}

void dfs2 (int u) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa[u]) {
            continue;
        }
        if (fabs(((double) 1.0 - dp[v] * ((double) w[i] / (double) 100.0))) < 1e-7) {
            dfs2(v);
            continue;
        }
        double las = (dp[u] - dp[v] * ((double) w[i] / (double) 100.0)) / ((double) 1.0 - dp[v] * ((double) w[i] / (double) 100.0));
        dp[v] = dp[v] + las * ((double) w[i] / (double) 100.0) * (1 - dp[v]);
        dfs2(v);
    }
}

int main () {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> ori[i];
        dp[i] = (double) ori[i] / (double) 100.0;
    }
    dfs1(1, 1, -1);
    dfs2(1);
    double res = 0.0;
    for (int i = 1; i <= n; ++i) {
        res += dp[i];
    }
    cout << fixed << setprecision(6) << res << '\n';
    return 0;
}