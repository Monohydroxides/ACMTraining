#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, inf = 0x3f3f3f3f;

int n, m;
int a[N], b[N];

int dp[2 * N][15][15];

int dfs (int round, int apick, int bpick) {
    if (round > 2 * n) return 0;
    if (((round & 1) && dp[round][apick][bpick] != -inf)
        || ((!(round & 1)) && dp[round][apick][bpick] != inf)) return dp[round][apick][bpick];
    int res;
    if (round % 2 == 1) {
        res = -inf;
        int banned = round / 2 - bpick;
        if (1 + apick + banned <= n && apick + 1 <= m)
            res = dfs(round + 1, apick + 1, bpick) + a[1 + apick + banned];
        res = max(res, dfs(round + 1, apick, bpick));
    } else {
        res = inf;
        int banned = round / 2 - apick;
        if (1 + bpick + banned <= n && bpick + 1 <= m)
            res = dfs(round + 1, apick, bpick + 1) - b[1 + bpick + banned];
        res = min(res, dfs(round + 1, apick, bpick));
    }
    return dp[round][apick][bpick] = res;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= 2 * n; i++)
        for (int j = 0; j <= 14; j++) 
            for (int k = 0; k <= 14; k++)
                dp[i][j][k] = (i & 1) ? -inf : inf;
    auto cmp = [] (int a, int b) { return a > b; };
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);
    cout << dfs(1, 0, 0) << '\n';
    return 0;
}