#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int v[1005], w[1005];
int n, m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            dp[i][j] = dp[i - 1][j];
            if(j - v[i] >= 0)   dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
