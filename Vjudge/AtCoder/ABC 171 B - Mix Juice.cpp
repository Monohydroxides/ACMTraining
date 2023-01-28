#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1010];
int dp[1010][1010];

int main () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int res = 0;
    for (int i = 1; i <= k; i++) res += a[i];
    cout << res << '\n';
    return 0;
}