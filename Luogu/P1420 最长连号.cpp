#include <bits/stdc++.h>
using namespace std;

// void work () {
    
//     return 0;
// }

// int main () {
//     int T;
//     cin >> T;
//     while (T--) {
//         work();
//     }
//     return 0;
// }

int main () {
    int n;
    cin >> n;
    vector<int> a(n), dp(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
    } 
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == 1) {
            dp[i] = dp[i - 1] + 1;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}