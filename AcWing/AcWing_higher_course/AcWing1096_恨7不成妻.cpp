#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<int> nums;
long long bse[30];
struct node {
    long long cnt, sum, sum2;
} f[20][10][10];

node dp (int pos, int sum, int num, int limit) {
    if (pos < 0) return node {sum && num, 0, 0};
    if (!limit && f[pos][sum][num].cnt > 0) return f[pos][sum][num];
    node res = {0, 0, 0};
    int up = limit == 1 ? nums[pos] : 9;
    for (int i = 0; i <= up; i++) {
        if (i != 7) {
            long long base = i * bse[pos] % mod;
            // cout << pos << " " << base << '\n';
            node cur = dp (pos - 1, (sum + i) % 7, (num * 10 + i) % 7, limit && i == up);
            res.cnt = (res.cnt + cur.cnt) % mod;
            res.sum = (res.sum + 1ll * base * cur.cnt % mod + cur.sum) % mod;
            res.sum2 = ((res.sum2 + 1ll * cur.cnt * base % mod * base % mod) % mod + cur.sum2 + 2ll * cur.sum % mod * base % mod) % mod;
        }
    }
    return limit == 1 ? res : f[pos][sum][num] = res;
}

int work (long long x) {
    nums.clear();
    while (x) {
        nums.push_back(x % 10);
        x /= 10;
    }
    return dp(nums.size() - 1, 0, 0, 1).sum2;
}

int main () {
    int T;
    cin >> T;
    long long l, r;
    bse[0] = 1;
    for (int i = 1; i < 30; i++) bse[i] = 1ll * bse[i - 1] * 10 % mod;
    while (T--) {
        cin >> l >> r;
        cout << ((work(r) - work(l - 1)) % mod + mod) % mod << '\n';
    }
    return 0;
}