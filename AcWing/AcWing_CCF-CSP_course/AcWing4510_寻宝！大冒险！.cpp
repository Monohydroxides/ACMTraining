#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 55;

int n, l, m;
int px, py, k, cnt, ans;
int x[N], y[N], a[M][M];

int main () {
    cin >> n >> l >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = m; ~i; i--) {
        for (int j = 0; j <= m; j++) {
            cin >> a[i][j];
            k += a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        px = x[i], py = y[i], cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (x[j] >= px && x[j] <= px + m && y[j] >= py && y[j] <= py + m) {
                a[x[j] - px][y[j] - py] ? cnt++ : cnt = -0x3f3f3f3f;
            }
        }
        ans += px + m <= l && py + m <= l && cnt == k;
    }
    cout << ans << '\n';
    return 0;
}