#include<bits/stdc++.h>
using namespace std;

int n;
int dp[32];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        int k = 0, cnt = 0;
        int tmp = x;
        while(x)
        {
            if(x & 1)   k = max(k, dp[cnt] + 1);
            x >>= 1;
            cnt++;
        }
        cnt = 0;
        while(tmp)
        {
            if(tmp & 1) dp[cnt] = max(dp[cnt], k);
            tmp >>= 1;
            cnt++;
        }
    }
    int res = 0;
    for(int i = 0; i < 32; ++i) res = max(res, dp[i]);
    cout << res << endl;
    return 0;
}