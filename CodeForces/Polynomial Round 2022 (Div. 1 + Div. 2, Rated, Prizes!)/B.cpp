#include <bits/stdc++.h>
using namespace std;

int a[100010];

void work () {
    int n, m, k;
    cin >> n >> m >> k;
    int ret = n / k + (n % k > 0);
    int cnt = n % k > 0? n % k: k;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        if (a[i] > ret) {
            cout << "NO\n";
            return;
        } else if (a[i] == ret) {
            if (cnt > 0) {
                cnt--;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    return;
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