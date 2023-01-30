#include <bits/stdc++.h>
using namespace std;

int n;
int a[5010];
int f[5010][5010], g[5010][5010];

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i)    cin >> a[i], a[i] += 1;
    int rev = 0, res = 0x3f3f3f3f, cnt = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = f[i - 1][j] + (a[i] < j);
            g[i][j] = g[i - 1][j] + (a[i] > j); 
        }
        rev += g[i][a[i]];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {  
            int cur = rev - g[i - 1][a[i]] - g[j - 1][a[j]] - f[j - 1][a[i]] + f[i][a[i]] + g[i - 1][a[j]] + g[j - 1][a[i]] + f[j - 1][a[j]] - f[i][a[j]];
            if (res > cur) {
                res = cur;
                cnt = 1;
            } else if (res == cur) {
                cnt++;
            }
        }
    }
    cout << res << " " << cnt << '\n';
    return 0;
}