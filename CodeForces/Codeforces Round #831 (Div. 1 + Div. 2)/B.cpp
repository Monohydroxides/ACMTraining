#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    long long a = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
        long long x, y;
        cin >> x >> y;
        b = max(b, max(x, y));
        a += min(x, y);
    }
    // cout << a << " " << b << '\n';
    cout << (a + b) * 2ll << '\n';
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