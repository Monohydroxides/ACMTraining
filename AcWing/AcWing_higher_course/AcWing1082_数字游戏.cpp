#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
int f[35][15];

int dp (int pos, int las, int limit) {
    if (pos < 0) return 1;
    if (limit == 0 && ~f[pos][las]) return f[pos][las];
    int res = 0, up = limit == 1? nums[pos] : 9;
    for (int i = las; i <= up; i++) {
        res += dp(pos - 1, i, limit && i == nums[pos]);
    }
    return limit ? res : f[pos][las] = res;
}

int work (int x) {
    if (!x) return 1;
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
    while (cin >> n >> m) {
        cout << work(m) - work(n - 1) << '\n';
    }
    return 0;
}