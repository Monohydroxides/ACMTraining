#include <stdio.h>
int map[25][25];
long long ans[25][25];
int move[8][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};
int main()
{
    int i, j;
    int hx, hy, bx, by;
    scanf("%d %d %d %d", &bx, &by, &hx, &hy);
    for (i = 0; i < bx + 1; i++)
    {
        for (j = 0; j < by + 1; j++)
        {
            map[i][j] = 1;
        }
    }
    for (i = 0; i < 8; i++)
    {
        if (hx + move[i][0] < 0 || hy + move[i][1] < 0 || hx + move[i][0] >= bx + 1 || hy + move[i][1] >= by + 1)
        {
            continue;
        }
        map[hx + move[i][0]][hy + move[i][1]] = 0;
    }
    map[hx][hy] = 0;
    ans[0][0] = 1;
    for (i = 0; i <= bx + 1; i++)
    {
        for (j = 0; j <= by + 1; j++)
        {
            if (map[i][j])
            {
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
                }
                else if (i - 1 >= 0)
                {
                    ans[i][j] = ans[i - 1][j];
                }
                else if (j - 1 >= 0)
                {
                    ans[i][j] = ans[i][j - 1];
                }
            }
        }
    }
    printf("%lld", ans[bx][by]);
}