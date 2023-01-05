#include <bits/stdc++.h>
using namespace std;

// a b c d e f g
// 0 1 2 3 4 5 6

vector<int> arr;
vector<int> e[7];
int vis[7];

void add (int a, int b) {
    e[a].push_back(b);
    e[b].push_back(a);
} 

void dfs (int u) {
    vis[u] = 1;
    for (auto v : e[u])
        if (arr[v] && !vis[v]) {
            vis[v] = 1;
            dfs(v);
        }
}

bool check (int state) {
    arr.clear();
    for (int i = 0; i < 7; i++) {
        if ((state >> i) & 1) arr.push_back(1);
        else arr.push_back(0);
    }
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 7; i++) {
        if (arr[i]) {
            dfs(i);
            break;
        }
    }
    for (int i = 0; i < 7; i++) if (!vis[i] && arr[i]) return false;
    return true;
}

int main () {
    add(0, 1), add(0, 5);
    add(1, 6), add(5, 6);
    add(4, 6), add(2, 6);
    add(4, 5), add(1, 2);
    add(3, 4), add(2, 3);

    int res = 0;
    for (int state = 1; state < (1 << 7); state++)
        if (check(state))
            res++;
    cout << res << '\n';
    return 0;
} 