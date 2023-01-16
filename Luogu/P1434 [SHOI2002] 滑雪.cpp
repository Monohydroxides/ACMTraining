#include <stdio.h>
int data[101][101], ans[101][101], book[101][101];
int move[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int r, c, ansnum;
int memdfs(int x, int y)
{
    if (ans[x][y])
    {
        return ans[x][y];
    }
    ans[x][y] = 1;
    int nx, ny;
    int i, j, temp;
    for (i = 0; i < 4; i++)
    {
        nx = x + move[i][0];
        ny = y + move[i][1];
        if ((nx >= 1 && nx <= r && ny >= 1 && ny <= c) && data[x][y] > data[nx][ny])
        {
            temp = memdfs(nx, ny);
            ans[x][y] = (temp + 1) > ans[x][y] ? (temp + 1) : ans[x][y];
        }
    }
    return ans[x][y];
}
int main()
{
    int i, j, temp;
    scanf("%d %d", &r, &c);
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            temp = memdfs(i, j);
            ansnum = ansnum > temp ? ansnum : temp;
        }
    }
    printf("%d", ansnum);
    return 0;
}