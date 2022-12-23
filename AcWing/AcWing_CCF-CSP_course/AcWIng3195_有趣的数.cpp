#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n;
int dp[1010][(1 << 4)];

int qmi (int a, int b) {
    int res = 1;
    while (b) { if (b & 1) {res = (long long) res * a % mod;} a = (long long) a * a % mod; b >>= 1;}
    return res;
} 

int add (int a, int b) {
    return (a + b) % mod;
}

int work (int cur, int state, int first) {
    if (dp[cur][state] != -1) {
        return dp[cur][state];
    }
    if (state == ((1 << 4) - 1)) {
        return qmi(2, n - cur);
    }
    if (cur == n) {
        return 0;
    }

    if (first) {
        return work(cur + 1, (state | (1 << 2)), 0);
    } else {
        int res = 0;
        for (int bit = 0; bit <= 3; bit++) {
            if (bit == 0 && ((state >> 1) & 1)) {
                continue;
            }
            if (bit == 2 && ((state >> 3) & 1)) {
                continue;
            }
            res = add(res, work(cur + 1, state | (1 << bit), 0));
        }
        return dp[cur][state] = res;
    }
}

int main () {
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << work(0, 0, 1) << '\n';
    return 0;
}