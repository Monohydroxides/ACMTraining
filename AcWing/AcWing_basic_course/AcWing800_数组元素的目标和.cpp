#include <bits/stdc++.h>
using namespace std;
int x;
int a[100010], b[100010];
int main() {
    int l, r;
    int n, m;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int j = 1; j <= m; ++j) {
        cin >> b[j];
    }
    r = m;
    for (l = 1; l <= n; ++l) {
        while (r > 0 && b[r] + a[l] > x) {
            --r;
        }
        if (b[r] + a[l] == x) {
            printf("%d %d", l - 1, r - 1);
            break;
        }
    }
    return 0;
}
