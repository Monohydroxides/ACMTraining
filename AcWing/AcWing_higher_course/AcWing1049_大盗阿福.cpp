#include <bits/stdc++.h>
using namespace std;

int a[100010];
int dp[100010];

void work() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++i) {
        if(i == 1) {
            dp[1] = a[1];
            continue;
        }
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }
    cout << dp[n] << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}
