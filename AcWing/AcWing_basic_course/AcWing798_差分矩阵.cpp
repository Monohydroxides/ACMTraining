#include <bits/stdc++.h>

int a[1010][1010], b[1010][1010];

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
            b[i][j] += a[i][j], b[i + 1][j] -= a[i][j], b[i][j + 1] -= a[i][j], b[i + 1][j + 1] += a[i][j];
        }
    }
    for (int i = 1; i <= q; ++i) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        b[x1][y1] += c, b[x1][y2 + 1] -= c, b[x2 + 1][y1] -= c, b[x2 + 1][y2 + 1] += c;

    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}

