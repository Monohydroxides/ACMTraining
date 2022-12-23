#include <bits/stdc++.h>

using namespace std;

int a[1010][1010];

int main() {
    int m, n, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int temp;
            scanf("%d", &temp);
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + temp;
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1]);
    }
    return 0;
}

