#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n, ans1, ans2;
int a[N + 1][N + 1];
bool vis[N + 1][N + 1];
int dxy[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, -1, -1, -1, 1, 1, 1, 1, -1};

void bfs (int x, int y, int type) {
    queue<pair<int, int>> qu;
    qu.push({x, y});
    vis[x][y] = 1;
    while (qu.size()) {
        auto cur = qu.front();
        qu.pop();
        for (int d = 0; d <= 7; d++) {
            int nx = cur.first + dxy[d][0], ny = cur.second + dxy[d][1];
            if (nx < 1 || nx > n || ny < 1 ||  ny > n) continue;
            if (a[nx][ny] == a[x][y] && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                qu.push({nx, ny});
            } else if (a[nx][ny] != a[x][y]) {
                if (type == 0) {
                    if (a[nx][ny] > a[x][y]) type = -1;
                    else type = 1;
                } else if (type == 1) {
                    if (a[nx][ny] > a[x][y]) {
                        type = 2;
                    }
                } else if (type == -1) {
                    if (a[nx][ny] < a[x][y]) {
                        type = 2;
                    }
                } else if (type == 2) {
                    continue;
                }
            }
        }
    }
    if (type == 1) {
        // cout << "1 " << x << " " << y << '\n';
        ans1++;
    } else if (type == -1) {
        // cout << "2 " << x << " " << y << '\n';
        ans2++;
    } else if (type == 0) {
        ans1++;
        ans2++;
    }
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) {
                bfs(i, j, 0);
            } 
        }
    }
    cout << ans1 << " " << ans2 << '\n';
    return 0;
}