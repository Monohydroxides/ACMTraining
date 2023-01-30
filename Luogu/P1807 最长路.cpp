#include <bits/stdc++.h>
using namespace std;

int n, m;
int dis[1510];
bool inq[1510];
vector<array<int, 2>> e[1510];

void spfa () {
    memset(dis, 0x87, sizeof dis);
    dis[1] = 0;
    queue<int> qu;
    qu.push(1);
    inq[1] = 1;
    while (qu.size()) {
        int cur = qu.front();
        qu.pop();
        inq[cur] = 0;
        for (auto [v, w] : e[cur]) {
            if (dis[v] < dis[cur] + w) {
                dis[v] = dis[cur] + w;
                if (!inq[v]) {
                    qu.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    spfa();
    if (dis[n] == 0x87878787) {
        cout << -1 << '\n';
    } else {
        cout << dis[n] << '\n';
    }
    return 0;
}