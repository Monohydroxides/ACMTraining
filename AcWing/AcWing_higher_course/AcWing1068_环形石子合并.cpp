#include <bits/stdc++.h>
using namespace std;

int n;
int a[410];
int dp1[410][410];
int dp2[410][410];
int presum[410];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i]; 
    }
    memset(dp1, 0x3f, sizeof dp1);
    for(int i = 1; i < n * 2; ++i) {
        presum[i] = presum[i - 1] + a[i];
        dp1[i][i] = 0;
    }
    for(int len = 2; len <= n * 2; ++len) {
        for(int l = 1; l + len - 1 <= n * 2; ++l) {
            int r = l + len - 1;
            for(int k = l; k < r; ++k) {
                dp1[l][r] = min(dp1[l][r], dp1[l][k] + dp1[k + 1][r] + presum[r] - presum[l - 1]);
                dp2[l][r] = max(dp2[l][r], dp2[l][k] + dp2[k + 1][r] + presum[r] - presum[l - 1]);
            }
        }
    }
    int minn = 0x3f3f3f3f, maxn = 0;
    for(int i = 1; i <= n; ++i) {
        minn = min(minn, dp1[i][i + n - 1]);
        maxn = max(maxn, dp2[i][i + n - 1]);
    }
    cout << minn << endl;
    cout << maxn << endl;
    return 0;
}
