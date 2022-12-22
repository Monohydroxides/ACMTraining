#include <stdio.h>
#include <iostream>
using namespace std;
char map[20][20];
int book[20][20];
int n, m, step;
int moveto[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y);
int main()
{
    int i, j, startx, starty;
    char temp;
    int isfind = 0;
    scanf("%d%d", &m, &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '@')
            {
                startx = i;
                starty = j;
            }
        }
    }
    fflush(stdin);
    getchar();
    dfs(startx, starty);
    cout << step;
}
void dfs(int x, int y)
{
    int i, j, nx, ny;
    book[x][y] = 1;
    step++;
    for (i = 0; i < 4; i++)
    {
        nx = x + moveto[i][0];
        ny = y + moveto[i][1];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == '#')
        {
            continue;
        }
        if (map[nx][ny] == '.' && book[nx][ny] == 0)
        {
            dfs(nx, ny);
        }
    }
}