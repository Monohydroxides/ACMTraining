#include <bits/stdc++.h>
using namespace std;

int n;
int f[60][262145];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[x][i] = i + 1;
    }
    int ans = 0;
    for (int i = 2; i < 60; i++) {
        for (int j = 1; j <= n; j++) {
            if (!f[i][j])
                f[i][j] = f[i - 1][f[i - 1][j]];
            if (f[i][j])
                ans = i;
        }
    }
    cout << ans << '\n';
    return 0;
}