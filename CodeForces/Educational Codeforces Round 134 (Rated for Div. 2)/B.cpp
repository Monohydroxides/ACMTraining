#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    if ((sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m) || abs(n - sx) + abs(m - sy) <= d
        || (sx - d <= 1 && sy - d <= 1) || (sx + d >= n && sy + d >= m)) {
        cout << -1 << '\n';
    } else {
        cout << n + m - 2 << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}