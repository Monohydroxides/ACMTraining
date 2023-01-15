#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n, m, k;
int cnt[1 << 6];
int dp[110][21][1 << 6][1 << 6];

int count (int x) {
    int res = 0;
    while (x) {
        if (x & 1) res++;
        x >>= 1;
    }
    return res;
}

bool check1 (int cur, int las) {
    if (((cur << 2) & las) || ((cur >> 2) & las)) return false;
    return true;
}

bool check2 (int cur, int llas) {
    if (((cur << 1) & llas) || ((cur >> 1) & llas)) return false;
    return true;
}

int main () {
    scanf("%d%d%d", &n, &m, &k);
    for (int state = 0; state < (1 << n); state++) {
        cnt[state] = count(state);
    }

    dp[0][0][0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int state = 0; state < (1 << n); state++) {
            if (cnt[state] > k) continue;
            for (int lasstate = 0; lasstate < (1 << n); lasstate++) {
                if (!check1(state, lasstate)) continue;
                for (int llasstate = 0; llasstate < (1 << n); llasstate++) {
                    if (!check2(state, llasstate) || !check1(lasstate, llasstate)) continue;
                    for (int p = 0; p <= k; p++) {
                        if (p + cnt[state] > k) break;
                        int& r = dp[i][p + cnt[state]][state][lasstate];
                        r = (r + dp[i - 1][p][lasstate][llasstate]) % mod;
                    }
                }
            }
        }
    }

    int res = 0;
    for (int state = 0; state < (1 << n); state++) {
        for (int lasstate = 0; lasstate < (1 << n); lasstate++) {
            res = (res + dp[m][k][state][lasstate]) % mod;
        }
    }
    printf("%d\n", res);
    return 0;
}