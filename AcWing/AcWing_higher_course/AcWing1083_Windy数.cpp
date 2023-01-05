#include <bits/stdc++.h>
using namespace std;

int dp[11][10];

void init() {
    for(int i = 0; i <= 9; ++i) dp[1][i] = 1;
    for(int i = 2; i <= 10; ++i) {
        for(int j = 0; j <= 9; ++j) {
            for(int k = 0; k <= 9; ++k) {
                dp[i][j] += abs(j - k) >= 2 ? dp[i - 1][k]: 0;
            }
        }
    }
}

int work(int x) {
    if(!x)  return 0;
    int tmp = x;
    vector<int> nums;
    while(tmp) {
        nums.push_back(tmp % 10);
        tmp /= 10;
    }
    int len = nums.size();
    int res = 0;
    for(int i = 1; i < len; ++i) {
        for(int j = 1; j <= 9; ++j) {
            res += dp[i][j];
        }
    }
    int las = -0x3f3f3f3f;
    for(int i = len - 1; i >= 0; --i) {
        for(int j = (i == len - 1); j < nums[i]; ++j) {
            if(abs(j - las) >= 2)    res += dp[i + 1][j];
        }
        if(abs(nums[i] - las) < 2)  break;
        las = nums[i];
        if(!i)  ++res;
    }
    return res;
}

int main() {
    int l, r;
    cin >> l >> r;
    init();
    cout << work(r) - work(l - 1) << endl;
    return 0;
}
