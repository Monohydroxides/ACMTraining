#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N];
long long pre[N][N];

int main () {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pre[i][j] = pre[i][j - 1] + a[i][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            pre[i][j] += pre[i - 1][j];
        }
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << pre[c][d] - pre[c][b - 1] - pre[a - 1][d] + pre[a - 1][b - 1] << '\n'; 
    }
    return 0;
}