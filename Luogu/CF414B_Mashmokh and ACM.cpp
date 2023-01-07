#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n, k;
int dp[2010][2010];

vector<int> fac[2010];

int main () {
    cin >> n >> k;
    for (int i = 1; i <= 2000; i++) 
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                fac[i].push_back(j);
                if (j * j != i) {
                    fac[i].push_back(i / j);
                }
            }
        }
    for (int i = 1; i <= n; i++) dp[1][i] = 1;
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto r : fac[j]) 
                dp[i][j] = (dp[i][j] +  dp[i - 1][r]) % mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[k][i]) % mod;
    }
    cout << ans << '\n';
    return 0;
}