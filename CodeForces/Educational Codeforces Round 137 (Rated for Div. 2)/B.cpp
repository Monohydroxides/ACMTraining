#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    if (n & 1) {
        cout << (n + 1) / 2 << " ";
        for (int l = 1; l <= n / 2; ++l) {
            cout << n - l + 1 << " ";
            cout << l << " ";
        }
        cout << '\n';
    } else {
        int r = n / 2;
        for (; r >= 1; --r, --n) {
            cout << r << " " << n << " ";
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