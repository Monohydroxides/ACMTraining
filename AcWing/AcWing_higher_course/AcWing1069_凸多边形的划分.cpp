#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;

int n;
int a[55];
i128 dp[55][55];

void print_i128 (i128 x) {
    stack<int> res;
    while (x) {
        res.push(x % 10);
        x /= 10;
    }
    while (res.size()) {
        cout << res.top();
        res.pop();
    }
    cout << '\n';
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int len = 3; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = ((i128) 1 << 120);
            // print_i128(dp[l][r]);
            for (int k = l + 1; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + (i128) a[l] * a[k] * a[r]);
            }
        }
    }
    print_i128(dp[1][n]);
    return 0;
}