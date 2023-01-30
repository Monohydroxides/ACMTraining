#include <bits/stdc++.h>
using namespace std;

int n;
int dp[80010];

vector<int> get (int x) {
    vector<int> fac;
    int u = x;
    for (int i = 2; i <= u / i; ++i) {
        if (x % i == 0) {
            fac.push_back(i);
            fac.push_back(x / i);
        }
    }
    sort(fac.begin(), fac.end());
    fac.erase(unique(fac.begin(), fac.end()), fac.end());
    return fac;
}

int main () {
    cin >> n;
    int res = 0x3f3f3f3f;
    for (int i = 1; i <= 2 * n; ++i) {
        dp[i] = dp[i - 1] + 1;
        vector<int> fac = get(i);
        for (int j = 0; j < fac.size(); ++j) {
            dp[i] = min(dp[i], dp[fac[j]] + 5 + 2 * (i / fac[j] - 1));
        }
        if (i >= n) {
            res = min(res, dp[i]);
        }
    }
    cout << res << '\n';
    return 0;
}