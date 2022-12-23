#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[100010], b[100010];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int j = 1; j <= m; ++j) {
        cin >> b[j];
    }
    for (int l = 1, r = 1; l <= n; ++l) {
        while (r <= m && b[r] != a[l]) {
            ++r;
        }
        if (r > m) {
            printf("No");
            return 0;
        }
        ++r;
    }
    printf("Yes");
    return 0;
}

