#include <stdio.h>
int n, k, sum = 0;
void dfs(int num, int times, int loopnumber)
{
    if (num < times)
    {
        return;
    }
    if (times == 1)
    {
        sum++;
        return;
    }
    for (int i = loopnumber; i <= num / times; i++)
    {
        dfs(num - i, times - 1, i);
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    dfs(n, k, 1);
    printf("%d", sum);
}