#include <stdio.h>
int map[100][100], book[100][100];
int m, n;
int mapcolor;
int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y);
int main()
{
    scanf("%d %d", &m, &n);
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (map[i][j] && book[i][j] == 0)
            {
                book[i][j] = 1;
                dfs(i, j);
                mapcolor++;
            }
        }
    }
    printf("%d", mapcolor);
    return 0;
}
void dfs(int x, int y)
{
    int i;
    int nx, ny;
    for (i = 0; i < 4; i++)
    {
        nx = x + move[i][0];
        ny = y + move[i][1];
        if (nx >= m || ny >= n || nx < 0 || ny < 0)
        {
            continue;
        }
        if (map[nx][ny] && book[nx][ny] == 0)
        {
            book[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
}   