#include <bits/stdc++.h>
using namespace std;

int n, k;
int vis[100010];

int main () {
    cin >> n >> k;
    queue<pair<int, int>> qu;
    qu.push({n, 0});
    vis[n] = 1;
    while (qu.size()) {
        auto cur = qu.front();
        qu.pop();
        if (cur.first == k) {
            cout << cur.second << '\n';
            break;
        }
        if (cur.first * 2 <= 1e5 && !vis[cur.first * 2]) {
            vis[cur.first * 2] = 1;
            qu.push({cur.first * 2, cur.second + 1});
        }
        if (cur.first + 1 <= 1e5 && !vis[cur.first + 1]) {
            vis[cur.first + 1] = 1;
            qu.push({cur.first + 1, cur.second + 1});
        }
        if (cur.first - 1 >= 0 && !vis[cur.first - 1]) {
            vis[cur.first - 1] = 1;
            qu.push({cur.first - 1, cur.second + 1});
        }
    }
    return 0;
}
