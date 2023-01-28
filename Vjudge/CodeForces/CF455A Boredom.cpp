#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int cnt[100010];
long long dp[100010];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1; i <= 100000; ++i)
    {
        if(cnt[i])
        {
            if(i == 1)
            {
                dp[i] = cnt[i];
            }
            else
            {
                dp[i] = max(dp[i - 1], dp[i - 2] + (long long) cnt[i] * i);
            }
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[100000] << endl;
    return 0;
}