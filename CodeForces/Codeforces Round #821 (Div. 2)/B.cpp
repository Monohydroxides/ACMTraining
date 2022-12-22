#include <bits/stdc++.h>
using namespace std;

void work () {
    int n, x, y;
    cin >> n >> x >> y;
    if ((x && y) || (!x && !y)) {
        cout << -1 << '\n';
        return;
    }
    int k = max(x, y);
    if ((n - 1) % (k)) {
        cout << -1 << '\n';
        return;
    }
    int idx = 1, cnt = 0;
    for (int i = 1; i <= n - 1; ++i) {
        cnt++;
        cout << idx << " ";
        if (cnt == k) {
            idx = i + 2;
            cnt = 0;
        }
    }
    cout << '\n';
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