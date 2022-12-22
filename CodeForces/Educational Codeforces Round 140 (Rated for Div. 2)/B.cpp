#include <bits/stdc++.h>
using namespace std;

int a[200010];

void work () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 2, a + 1 + n);
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[1]) {
            if ((a[i] - a[1]) & 1) {
                a[1] += (a[i] - a[1] + 1) / 2;
            } else {
                a[1] = (a[1] + a[i]) / 2;
            }
        }
    }
    cout << a[1] << '\n';
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