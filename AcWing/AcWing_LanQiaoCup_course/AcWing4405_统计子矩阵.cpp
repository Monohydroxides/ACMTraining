#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int a[510][510];

int main () {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            for (int s = 1, t = 1; t <= n; t++) {
                while (s <= t && a[t][j] - a[s - 1][j] - a[t][i - 1] + a[s - 1][i - 1] > k) s++;
                if (s <= t) ans += t - s + 1;
            }
        }
    }
    cout << ans << '\n';
}