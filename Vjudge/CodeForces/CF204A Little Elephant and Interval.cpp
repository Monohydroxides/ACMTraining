#include <bits/stdc++.h>
using namespace std;

vector<int> nums;

long long dp[20][15];

long long dfs (int pos, int st, int las, int limit, int lead) {
    if (pos < 0) return st == las;
    if (st && !limit && ~dp[pos][st]) return dp[pos][st];
    long long res = 0;
    int up = limit == 1 ? nums[pos] : 9;
    for (int i = 0; i <= up; i++) {
        res += dfs(pos - 1, lead ? i : st, i, limit && i == up, lead && (i == 0));
    }
    if (!limit && st) dp[pos][st] = res;
    return res;
}

long long work (long long x) {
    nums.clear();
    while (x) {
        nums.push_back(x % 10);
        x /= 10;
    }
    return dfs(nums.size() - 1, 0, 0, 1, 1);
}

int main () {
    long long l, r;
    cin >> l >> r;
    memset(dp, -1, sizeof dp);
    cout << work(r) - work(l - 1) << '\n';
    return 0;
}