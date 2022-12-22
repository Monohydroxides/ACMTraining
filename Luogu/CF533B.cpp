#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n;
int h[N], e[N], ne[N], idx;

int w[N];
long long dp[N][2];

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs (int u) {
    dp[u][1] = -INF;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int v = e[i];
        dfs(v);
        long long x = dp[u][0], y = dp[u][1];
        dp[u][0] = max(dp[v][0] + x, dp[v][1] + y);
        dp[u][1] = max(dp[v][0] + y, dp[v][1] + x);
    }
    dp[u][1] = max(dp[u][1], dp[u][0] + w[u]);
}

int main () {
    memset(h, -1, sizeof h);
    cin >> n;
    int p, x;
    for (int i = 1; i <= n; ++i) {
        cin >> p >> x;
        if (p != -1) {
            add(p, i);
        }
        w[i] = x;
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}