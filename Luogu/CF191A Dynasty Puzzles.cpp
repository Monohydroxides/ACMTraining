#include <bits/stdc++.h>
using namespace std;

int n;
char str[15];
int dp[30][30];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> str;
        int l = str[0] - 'a', r = str[strlen(str) - 1] - 'a';
        for(int j = 0; j < 26; ++j)
        {
            if(dp[j][l])
            {
                dp[j][r] = max(dp[j][r], dp[j][l] + (int) strlen(str));
            }
        }
        dp[l][r] = max(dp[l][r], (int) strlen(str)); 
    }
    int res = 0;
    for(int i = 0; i < 26; ++i)
    {
        res = max(res, dp[i][i]);
    }
    cout << res << endl;
    return 0;
}