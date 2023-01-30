#include <bits/stdc++.h>
using namespace std;

int n;
long double mat[20][20];
long double dp[1 << 19];

int countBit(int x) {
    int res = 0;
    while(x) {
        if(x & 1)   ++res;
        x >>= 1;
    }
    return res;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) cin >> mat[i][j];
    dp[(1 << n) - 1] = 1.0;
    for(int st = (1 << n) - 1; st > 0; --st) {
        for(int i = 1; i <= n; ++i) {
            if((st & (1 << (i - 1))))  continue;
            int cnt = countBit(st);
            for(int j = 1; j <= n; ++j) {
                if(st & (1 << (j - 1))) {
                    dp[st] += dp[st | (1 << (i - 1))] * mat[j][i] * (long double) 2.0 / (long double) cnt / (long double) (cnt + 1);
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << fixed << setprecision(6) << dp[1 << i] << " ";
    }
    cout << endl;
    return 0;
}