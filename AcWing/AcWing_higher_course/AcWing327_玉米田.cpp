#include <bits/stdc++.h>
using namespace std;

const int N = 13, mod = 1e8;

int n, m;
int a[N][N];
int dp[N][(1 << 12)];
vector<int> leg[N];

bool check1 (int row, int state) {
    if (state & (state << 1)) return false;
    for (int j = 1; j <= m; j++) {
        if (((state >> (j - 1)) & 1)){
            if (!a[row][j]) return false;
        } 
    }
    return true;
}

bool check2 (int cur, int las) {
    while (cur && las) {
        int cb = cur & 1;
        int lb = las & 1;
        if (cb && lb) return false;
        cur >>= 1;
        las >>= 1;
    }
    return true;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        } 
    }
    for (int i = 1; i <= n; i++) {
        for (int state = 0; state < (1 << m); state++) {
            if (check1(i, state)) {
                leg[i].push_back(state);
            }
        }
    }

    for (int cur : leg[1]) {
        dp[1][cur] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int cur : leg[i]) {
            for (int las : leg[i - 1]) {
                if (check2(cur, las)) {
                    dp[i][cur] = (dp[i][cur] + dp[i - 1][las]) % mod;
                }
            }
        }
    }
    int res = 0;
    for (int state : leg[n]) {
        res = (res + dp[n][state]) % mod;
    }
    cout << res << '\n';
    return 0;
}