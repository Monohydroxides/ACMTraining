#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
int f[40][2];

int dp (int pos, int st, int limit) {
    if (pos < 0) return 1;
    if (limit == 0 && ~f[pos][st]) return f[pos][st];
    int res = 0, up = limit == 1 ? nums[pos] : 9;
    for (int i = 0; i <= up; i++) {
        if (i == 4 || (i == 2 && st == 1)) continue;
        res += dp(pos - 1, i == 6, limit && i == nums[pos]);
    }
    return limit == 1 ? res : f[pos][st] = res;
}

int work (int x) {
    nums.clear();
    while (x) {
        nums.push_back(x % 10);
        x /= 10;
    }
    memset(f, -1, sizeof f);
    return dp(nums.size() - 1, 0, 1);
}

int main () {
    int n, m;
    while (cin >> n >> m, n || m) {
        cout << work(m) - work(n - 1) << '\n';
    }
    return 0;
}