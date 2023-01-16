#include <stdio.h>
int dp[101][1001];
int time[101], value[101];
int max(int a, int b);
int main()
{
    int totaltime, num;
    int i, j;
    scanf("%d %d", &totaltime, &num);
    for (i = 1; i <= num; i++)
    {
        scanf("%d %d", &time[i], &value[i]);
    }
    for (i = 1; i <= num; i++)
    {
        for (j = 1; j <= totaltime; j++)
        {
            if (time[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + value[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d", dp[num][totaltime]);
    return 0;
}
int max(int a, int b)
{
    return a > b ? a : b;
}