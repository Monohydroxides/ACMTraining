#include <bits/stdc++.h>
using namespace std;

int n, r;
int a[5010][5010];

int main () {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;
        a[x][y] += w;
    }
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            a[i][j] = a[i][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            a[i][j] = a[i - 1][j] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            int x = max(1, i - r + 1);
            int y = max(1, j - r + 1);
            ans = max(ans, a[i][j] - a[x - 1][j] - a[i][y - 1] + a[x - 1][y - 1]);
        }
    }
    cout << ans << "\n";
    return 0;
}