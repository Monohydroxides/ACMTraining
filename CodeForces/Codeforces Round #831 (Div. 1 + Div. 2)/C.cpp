#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int res = 2 * a[n] - a[1] - a[n - 1];
    for (int i = n - 1; i >= 4; --i) {
        res = max(res, 2 * a[i] - a[1] - a[i - 1]);
    }
    res = max(res, a[n] - a[1] + a[2] - a[1]);
    for (int i = 2; i <= n - 2; ++i) {
        res = max(res, a[n] - 2 * a[i] + a[i + 1]);
    }
    cout << res << '\n';
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}