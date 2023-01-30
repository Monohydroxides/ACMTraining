#include <bits/stdc++.h>
using namespace std;

int n;
int a[5010], pre[5010];
int dp[5010], l[5010];

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (pre[l[j]] + pre[i] >= 2 * pre[j]) {
                dp[i] = dp[j] + i - j - 1;
                l[i] = j;
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}