#include <bits/stdc++.h>
using namespace std;

int a[110], b[110];

void work () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    a[1] = b[1];
    if (a[1] < 0) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (b[i] == 0) {
            a[i] = a[i - 1];
            continue;
        }
        // cout << i << " " << a[i - 1] + b[i] << " " << a[i - 1] - b[i] << '\n';
        if (a[i - 1] + b[i] >= 0 && a[i - 1] - b[i] >= 0) {
            cout << -1 << '\n';
            return;
        } else {
            a[i] = max(a[i - 1] + b[i], a[i - 1] - b[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
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