#include <bits/stdc++.h>
using namespace std;

int n;
int a[510];
int dp[510][510];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) dp[i][i] = 1;
    for(int len = 2; len <= n; ++len)
    {
        for(int l = 1; l + len - 1 <= n; ++l)
        {
            int r = l + len - 1;
            dp[l][r] = 0x3f3f3f3f;
            if(a[l] == a[r])
            {
                if(l + 1 == r)
                {
                    dp[l][r] = 1;
                }
                else
                {
                    dp[l][r] = dp[l + 1][r - 1];
                }
            }
            for(int k = l; k < r; ++k)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}