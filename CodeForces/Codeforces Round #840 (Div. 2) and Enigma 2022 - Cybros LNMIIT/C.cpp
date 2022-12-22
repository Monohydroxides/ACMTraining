#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i: a) {
        cin >> i;
    }
    if (n > 3) {
        long long maxn = 0;
        for (auto i: a) {
            maxn = max(maxn, i);
        }
        cout << (long long) maxn * n << '\n';
    } else if (n == 2) {
        cout << max(a[0] + a[1], abs(a[1] - a[0]) * 2) << '\n';
    } else if (n == 3) {
        cout << max({3 * (abs(a[0] - a[1])), 3 * (abs(a[2] - a[1])), 3 * a[0], 3 * a[2], a[0] + a[1] + a[2]}) << '\n';
    }
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