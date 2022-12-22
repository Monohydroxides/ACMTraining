#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> nums;
ll dp[12][10][10][2][2][2];

ll dfs(int pos, int las1, int las2, int combo3, int has4, int has8, int upperbound) {
    if(has4 && has8)    return 0;
    if(pos < 0) return combo3;
    int maxn = upperbound? nums[pos]: 9;
    if(!upperbound && dp[pos][las1][las2][combo3][has4][has8] != -1)    return dp[pos][las1][las2][combo3][has4][has8];
    ll res = 0;
    for(int i = 0; i <= maxn; ++i) {
        res += dfs(pos - 1, i, las1, combo3 || ((i == las1) && (i == las2)), has4 || (i == 4), has8 || (i == 8), upperbound && (i == maxn));
    }
    if(!upperbound) dp[pos][las1][las2][combo3][has4][has8] = res;
    return res;
}

ll count(ll x) {
    nums.clear();
    memset(dp, -1, sizeof dp);

    ll tmp = x;
    while(tmp) {
        nums.push_back(tmp % 10);
        tmp /= 10;
    }
    if(nums.size() < 11)    return 0;
    ll res = 0;
    for(int i = 1; i <= nums[nums.size() - 1]; ++i) {
        res += dfs(nums.size() - 2, i, -1, 0, i == 4, i == 8, i == nums[nums.size() - 1]);
    }
    return res;
}

int main() {
    ll l, r;
    cin >> l >> r;
    cout << count(r) - count(l - 1) << endl;
    return 0;
}