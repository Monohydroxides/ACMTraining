#include <bits/stdc++.h>
using namespace std;

int n, m;

bool vis[30];
int ans[30], ptr;

void dfs (int cur, int pos) {
    if (ptr == m) {
        for (int i = 1; i <= ptr; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    if (cur > n) return;
    
    // vis[cur] = 1;
    ans[++ptr] = cur;
    dfs(cur + 1, pos + 1);
    ptr--;
    // vis[cur] = 0;

    dfs(cur + 1, pos);
}

int main () {
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}