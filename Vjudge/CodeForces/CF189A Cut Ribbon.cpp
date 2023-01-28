#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n, a[4];
int dp[4010];

int main()
{
    cin >> n >> a[1] >> a[2] >> a[3];
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= 3; ++i)
    {   
        for(int j = a[i]; j <= n; ++j)
        {
            if(dp[j - a[i]] != -1)  dp[j] = max(dp[j], dp[j - a[i]] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}