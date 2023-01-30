#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
int w[19];
map<int, int> mp[19];
ll dp[1 << 18][19];

int countBit(int x)
{
    int res = 0;
    while(x)
    {
        if(x & 1)   res++;
        x >>= 1;
    }
    return res;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= k; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        mp[x][y] = c;
    }

    for(int i = 1; i <= n; ++i)
    {
        dp[1 << (i - 1)][i] = w[i];
    }
    for(int i = 1; i < 1 << n; ++i)
    {
        if(countBit(i) >= m)    continue;
        for(int j = 1; j <= n; ++j)
        {
            if(!((i >> (j - 1)) & 1))  continue;
            for(int p = 1; p <= n; ++p)
            {
                if((i >> (p - 1)) & 1)  continue;
                dp[i | (1 << (p - 1))][p] = max(dp[i | (1 << (p - 1))][p], dp[i][j] + w[p] + mp[j][p]);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < 1 << n; ++i)
    {
        if(countBit(i) > m) continue;
        for(int j = 1; j <= n; ++j)
        {
            if((i >> (j - 1)) & 1)  res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}