#include <bits/stdc++.h>
using namespace std;

int n, m;
int k[110];
long long presum[110][110];
long long f[110][10010];
long long g[110][10010];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j) {
            int x;
            cin >> x;
            presum[i][j] = presum[i][j - 1] + x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(k[i], m); ++j) {
            for (int p = 0; p <= j; ++p) {
                f[i][j] = max(f[i][j], presum[i][p] + presum[i][k[i]] - presum[i][k[i] - j + p]);
            }  
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int p = 0; p <= min(j, k[i]); ++p) {
                g[i][j] = max(g[i][j], g[i - 1][j - p] + f[i][p]);
            }
        }
    }
    cout << g[n][m] << endl;
    return 0;
}