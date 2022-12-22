#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];

void work() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    int res = 0;
    auto check = [&] (int x) -> int {
        vector<int> c(n + 1), d(n + 1);
        for (int i = 1; i <= n; ++i) {
            c[i] = a[i] & x;
            d[i] = (~b[i]) & x;
        }
        sort(c.begin() + 1, c.end());
        sort(d.begin() + 1, d.end());
        for (int i = 1; i <= n; ++i) {
            if(c[i] != d[i]) {
                return 0;
            }
        }
        return 1;
    };
    for (int cnt = 29; cnt >= 0; --cnt) {
        if (check(res | 1 << cnt)) {
            res |= 1 << cnt;
        }
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}