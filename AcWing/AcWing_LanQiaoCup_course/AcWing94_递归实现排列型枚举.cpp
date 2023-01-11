#include <bits/stdc++.h>
using namespace std;

int n;
int vis[10];
int ans[10], ptr;

void dfs (int pos) {
    if (pos > n) {
        for (int i = 1; i <= ptr; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            ans[++ptr] = i;
            dfs(pos + 1);
            ptr--;
            vis[i] = 0;
        }
    }
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vis[i] = 1;
        ans[++ptr] = i;
        dfs(2);
        ptr--;
        vis[i] = 0;
    }
    return 0;
}