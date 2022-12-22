#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int h[N], e[N * 2], ne[N * 2], idx;
long long dp[N][2];

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1 (int u, int father, int depth) {
    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == father) {
            continue;
        }
        cnt++;
        dfs1(v, u, depth + 1);
        dp[u][0] += dp[v][0];
        dp[u][1] = max(dp[u][1], dp[v][1] + 1);
    }
    if (cnt == 0) {
        dp[u][1]++;
        dp[u][0]++;
    }
    dp[u][0] = max(dp[u][1], dp[u][0]);
}

int main () {
    int n;
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        add(x, i), add(i, x);
    }
    dfs1(1, -1, 1);
    cout << dp[1][0] << '\n';
    return 0;
}