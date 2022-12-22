#include <stdio.h>
long long dp[1001][1001];
unsigned win[1001], lose[1001], use[1001];
int max(int a, int b);
int main()
{
    int i, j;
    int n, totaluse;
    scanf("%d %d", &n, &totaluse);
    for (i = 1; i <= n; i++)
    {
        scanf("%u %u %u", &lose[i], &win[i], &use[i]);
    }
    for (i = 1; i <= n; i++)
    {
        for (j = totaluse; j >= 0; j--)
        {
            if (j >= use[i])
            {
                dp[i][j] = max(dp[i - 1][j - use[i]] + win[i], dp[i - 1][j] + lose[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + lose[i];
            }
        }
    }
    printf("%lld", 5 * dp[n][totaluse]);
    return 0;
}
int max(int a, int b)
{
    return a > b ? a : b;
}