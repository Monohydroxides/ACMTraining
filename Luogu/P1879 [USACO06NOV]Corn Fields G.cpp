#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[12];
int dp[1 << 12][12];

int main () {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x == 0) {
                a[i] |= (1 << j);
            }
        }
    }
    for (int state = 0; state < (1 << n); ++state) {
        if ((state & a[0]) || (state & (state << 1))) {
            continue;
        }
        dp[state][0] = 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int las = 0; las < (1 << n); ++las) {
            if ((las & a[i - 1]) || (las & (las << 1))) {
                continue;
            }
            for (int state = 0; state < (1 << n); ++state) {
                if ((state & a[i]) || (state & (state << 1)) || (state & las)) {
                    continue;
                }
                dp[state][i] = (dp[state][i] + dp[las][i - 1]) % 100000000;
            }
        }
    }
    int res = 0;
    for (int state = 0; state < (1 << n); ++state) {
        res = (res + dp[state][m - 1]) % 100000000;
    }
    cout << res << endl;
    return 0;
}