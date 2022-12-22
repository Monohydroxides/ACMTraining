#include <bits/stdc++.h>
using namespace std;

int a[110];

void work () {
    int res = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        res += (a[i] / (2 * a[1] - 1)) - (a[i] % (2 * a[1] - 1) == 0);
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