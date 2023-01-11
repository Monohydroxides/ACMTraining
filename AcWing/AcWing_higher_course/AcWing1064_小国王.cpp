#include <bits/stdc++.h>
using namespace std;

int n, k;
long long dp[11][(1 << 10)][101];
vector<int> legal;
map<int, int> cnt;

int count (int state) {
    if (cnt.count(state)) return cnt[state];
    int tmp = state;
    int res = 0;
    while (tmp) {
        if (tmp & 1) res++;
        tmp >>= 1;
    }
    return cnt[state] = res;
}

bool check (int las, int cur) {
    if (las & cur) {
        return false;
    }
    if (((las >> 1) & cur) || ((las << 1) & cur)) {
        return false;
    }
    if (((cur >> 1) & las) || ((cur << 1) & las)) {
        return false;
    }
    return true;
}

int main () {
    cin >> n >> k;
    for (int state = 0; state < (1 << n); state++) {
        if (!(state & (state << 1))) {
            legal.push_back(state);
            dp[1][state][count(state)] = 1;
        }
    }
    // cout << legal.size() << '\n';
    for (int i = 2; i <= n; i++) {
        for (int las : legal) {
            for (int cur : legal) {
                if (!check(las, cur)) continue;
                for (int t = 0; t <= k - count(cur); t++) {
                    dp[i][cur][t + count(cur)] += dp[i - 1][las][t];
                }
            }
        }
    }
    long long res = 0;
    for (int cur : legal) {
        res += dp[n][cur][k];
    }
    cout << res << '\n';
    return 0;
}
