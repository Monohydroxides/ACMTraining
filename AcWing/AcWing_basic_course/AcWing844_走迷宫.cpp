#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110;
int n, m;
int d[N][N], g[N][N];
int dxy[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
queue<pair<int, int>> q;
void bfs(){
    q.push({0, 0});
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = now.first + dxy[i][0], ny = now.second + dxy[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] || d[nx][ny])    continue;
            d[nx][ny] = d[now.first][now.second] + 1;
            q.push({nx, ny});
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> g[i][j];
    bfs();
    printf("%d", d[n - 1][m - 1]);
    return 0;
} 
