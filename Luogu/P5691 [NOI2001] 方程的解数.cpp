#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10][3];
unordered_map<int, int> mp;
int ans;

int qmi (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
void dfs1 (int cur, int res) {
    if (cur > (n + 1) / 2) {
        mp[res]++;
        return;
    }
    for (int i = 1; i <= m; i++) {
        dfs1(cur + 1, res + a[cur][1] * qmi(i, a[cur][2]));
    }
}

void dfs2 (int cur, int res) {
    if (cur > n) {
        ans += mp[-res];
        return;
    }
    for (int i = 1; i <= m; i++) {
        dfs2(cur + 1, res + a[cur][1] * qmi(i, a[cur][2]));
    }
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][1] >> a[i][2];
    }
    dfs1(1, 0);
    dfs2((n + 1) / 2 + 1, 0);
    cout << ans << "\n";
    return 0;
}