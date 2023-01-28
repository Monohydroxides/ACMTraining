#include <bits/stdc++.h>
using namespace std;

const int N = 1000010, mod = 1e9 + 7;

int n;
int a[100010];
int dp[1000010];

int main()
{
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        vector<int> fact;
        for(int j = 1; j <= a[i] / j; ++j)
        {
            if(a[i] % j == 0)
            {
                fact.emplace_back(j);
                if(a[i] / j != j)   fact.emplace_back(a[i] / j);
            }
        }
        sort(fact.begin(), fact.end(), greater<int>());
        for(int j = 0; j < fact.size(); ++j)
        {
            dp[fact[j]] = (dp[fact[j]] + dp[fact[j] - 1]) % mod;
        }
    }
    long long res = 0;
    for(int i = 1; i <= 1000000; ++i)
    {
        res = (res + dp[i]) % mod;
    }
    cout << res << endl;
    return 0;
}