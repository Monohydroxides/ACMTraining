#include <bits/stdc++.h>
using namespace std;

int a[110];

void work () {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i <= 100; ++i) {
        a[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
    int res = 0;
    for (int i = 0; i <= 100; ++i) {
        if (a[i] > c) {
            res += c;
        } else {
            res += a[i];
        }
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