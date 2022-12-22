#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = n; i >= 1; --i) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        if (n == 1 || n == 3) {
            cout << -1 << "\n";
            return;
        }
        cout << n << " " << n - 1 << " ";
        for (int i = 1; i <= n - 2; ++i) {
            cout << i << " ";
        }
        cout << '\n';
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