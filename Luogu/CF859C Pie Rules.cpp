#include <bits/stdc++.h>
using namespace std;

int n;
int a[55];
long long lassum[55];
long long dp[55];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        lassum[i] = lassum[i + 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        dp[i] = max(dp[i + 1], lassum[i + 1] - dp[i + 1] + a[i]);
    }
    cout << lassum[1] - max(dp[1], lassum[1] - dp[1]) << " " << max(dp[1], lassum[1] - dp[1]) << "\n";
    return 0;
}