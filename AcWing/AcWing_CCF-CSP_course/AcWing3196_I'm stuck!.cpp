// copied from: https://www.acwing.com/solution/content/35631/
// author: Hasity
// dfs
#include <iostream>
#include <cstring>
using namespace std;

const int N = 55;
char g[N][N];//保存地图
bool st1[N][N], st2[N][N];// 记录可达性
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};//上下左右四个方向

bool check(int x, int y, int k)//判断 x, y 是否能走到方向为 k 的那个点。k = 0, 1, 2, 3 分别代表向上，向左，向下，向右走
{
    if(g[x][y] == 'T' || g[x][y] == '+' || g[x][y] == 'S') return true;// T, +, S 能走到各个方向
    if(g[x][y] == '.' && k == 2) return true;// . 只能向下走 
    if(g[x][y] == '-' && (k == 1 || k == 3)) return true;// - 向左向右走
    if(g[x][y] == '|' && (k == 0 || k == 2)) return true;// | 向上向下走
    return false;
}

void dfs1(int x, int y)//深度优先遍历，求出 S 能到的所有点
{
    st1[x][y] = true;//能走到当前点，状态置为 true
    for(int i = 0; i < 4; i++)//向4个方向走
    {
        int a = x + dx[i], b = y + dy[i];
        if(check(x, y, i) && !st1[a][b] && g[a][b] != '#')//如果当前位置能走到下一位置，并且下一位置没被走过，并且不是 #，走到下一位置
            dfs1(a, b);
    }
}

void dfs2(int x, int y)//深度优先遍历，求出能走到 T 的所有点
{
    st2[x][y] = true;//当前点能走回，状态置为 true
    for(int i = 0; i < 4; i++)//四个方向向当前点走
    {
        int a = x + dx[i], b = y + dy[i];
        int k = i ^ 2;//某个点能否走到 x，y, 与 x, y 走到该点方向相反，0 -> 2, 1 -> 3, 2 -> 0, 3 -> 1。 
        if(check(a, b, k) && !st2[a][b] )
            dfs2(a, b);
    }
}

int main()
{
    int n, m;
    int s_x, s_y, e_x, e_y;// s_x, s_y：记录 S 的位置，e_x, e_yT：记录 T 的位置。
    cin >> n >> m;
    memset(g,'#',sizeof(g));//初始状态全部为墙


    for(int i = 1; i <= n; i++)// 从 1 1 开始存储，可以避免边界处理
    {
        for(int j = 1; j<= m; j++)
            {
                cin >> g[i][j];
                if(g[i][j] == 'S')// 找到 S 
                    s_x = i, s_y = j;
                if(g[i][j] == 'T')// 找到 T
                    e_x = i, e_y = j;
            }
    }

    dfs1(s_x, s_y);//求出 S 能走到的所有点

    if(!st1[e_x][e_y])// S 不能走到 T
    {
        cout << "I'm stuck!";
        return 0;
    }

    dfs2(e_x, e_y);//求出能走到 T 的所有点

    int res = 0;

    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            if(st1[i][j] && !st2[i][j])// S 能到 g[i][j], g[i][j] 不能到 T
                res++;
        }
    }
    cout << res;

}
