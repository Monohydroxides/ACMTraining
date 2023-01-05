#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
 
int n, m, x;
int a[N];
int dp[N];
map<int, int> loc;
 
int main () {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (loc.count(a[i] ^ x)) {
            dp[i] = max(dp[i - 1], loc[a[i] ^ x]);
        } else {
            dp[i] = dp[i - 1];
        }
        loc[a[i]] = i;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (dp[r] >= l) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}