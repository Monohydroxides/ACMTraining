#include <stdio.h>
int data[1001][1001];
int r, ans;
int dp[1001][1001];
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int i, j;
    scanf("%d", &r);
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= i; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }
    dp[1][1] = data[1][1];
    for (i = 2; i <= r; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (j == 1)
            {
                dp[i][j] = dp[i - 1][j] + data[i][j];
            }
            else if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] + data[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + data[i][j];
            }
        }
    }
    for (j = 1; j <= r; j++)
    {
        ans = max(ans, dp[r][j]);
    }
    printf("%d", ans);
    return 0;
}