// 这份代码被卡常了
// 理论复杂度为 O(100 * (N + M))，一共 5e6 次计算，复杂度上没有问题
// 不想手写哈希了

#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

int n, m;
unordered_map<int, unordered_map<int, int>> mp; // [x, y, id]
struct bomb {
    int x, y, r;
} bmb[N];
int tag[N];

int head[N], nxt[N * 2], to[N * 2], eid;

void add (int a, int b) {
    to[eid] = b, nxt[eid] = head[a], head[a] = eid++;
}

bool check (int st, int ed, int ra) {
    long long dx2 = bmb[st].x - bmb[ed].x;
    long long dy2 = bmb[st].y - bmb[ed].y;
    dx2 = dx2 * dx2, dy2 = dy2 * dy2;
    if (dx2 + dy2 <= (long long) ra * ra) {
        return true;
    }
    return false;
}

bool check2 (int x, int y, int ra, int id) {
    long long dx2 = x - bmb[id].x;
    long long dy2 = y - bmb[id].y;
    dx2 = dx2 * dx2, dy2 = dy2 * dy2;
    if (dx2 + dy2 <= (long long) ra * ra) {
        return true;
    }
    return false;
}

void dfs (int u) {
    tag[u] = 1;
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        if (!tag[v]) dfs(v);
    }
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(head, -1, sizeof head);
    for (int i = 1; i <= n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        bmb[i] = {x, y, r};
        for (int xx = x - 10; xx <= x + 10; xx++) {
            if (mp.count(xx)) {
                for (int yy = y - 10; yy <= y + 10; yy++) {
                    if (mp[xx].count(yy)) {
                        int cur = mp[xx][yy];
                        if (check(i, cur, r)) {
                            add(i, cur);
                        } 
                        if (check(cur, i, bmb[cur].r)) {
                            add(cur, i);
                        } 
                    }
                }
            }
        }
        mp[x][y] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        for (int xx = x - r; xx <= x + r; xx++) {
            if (!mp.count(xx)) continue;
            for (int yy = y - r; yy <= y + r; yy++) {
                if (mp[xx].count(yy)) {
                    if (check2(x, y, r, mp[xx][yy])) {
                        if (!tag[mp[xx][yy]])
                            dfs(mp[xx][yy]);
                    }
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (tag[i]) res++;
    }
    cout << res << '\n';
    return 0;
}