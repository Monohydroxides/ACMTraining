#include <bits/stdc++.h>
using namespace std;;

int dp[65][55][105][85];

int main () {
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0][0] = 0;
    for (int i = 1; i <= 60; ++i) {
        for (int j = 0; j <= 50; ++j) {
            for (int k = 0; k <= 100; ++k) {
                for (int l = 0; l <= 80; ++l) {
                    int& cur = dp[i][j][k][l];
                    cur = dp[i - 1][j][k][l] + 60;
                    if (j >= 5) {
                        if (cur > dp[i - 1][j - 5][k][l]) {
                            cur = dp[i - 1][j - 5][k][l];
                        }
                    }
                    if (j >= 3) {
                        if (k >= 1) {
                            if (cur > dp[i - 1][j - 3][k - 1][l] + 9) {
                                cur = dp[i - 1][j - 3][k - 1][l] + 9;
                            }
                        }
                        if (l >= 1) {
                            if (cur > dp[i - 1][j - 3][k][l - 1] + 7) {
                                cur = dp[i - 1][j - 3][k][l - 1] + 7;
                            }
                        }
                    }
                    if (j >= 2) {
                        if (k >= 2) {
                            if (cur > dp[i - 1][j - 2][k - 2][l] + 6) {
                                cur = dp[i - 1][j - 2][k - 2][l] + 6;
                            }
                        }
                        if (k >= 1) {
                            if (l >= 1) {
                                if (cur > dp[i - 1][j - 2][k - 1][l - 1] + 4) {
                                    cur = dp[i - 1][j - 2][k - 1][l - 1] + 4;
                                }
                            }
                        }
                        if (l >= 2) {
                            if (cur > dp[i - 1][j - 2][k][l - 2] + 2) {
                                cur = dp[i - 1][j - 2][k][l - 2] + 2;
                            }
                        }
                    }
                    if (j >= 1) {
                        if (k >= 3) {
                            if (cur > dp[i - 1][j - 1][k - 3][l] + 3) {
                                cur = dp[i - 1][j - 1][k - 3][l] + 3;
                            }
                        }
                        if (k >= 2) {
                            if (l >= 1) {
                                if (cur > dp[i - 1][j - 1][k - 2][l - 1] + 1) {
                                    cur = dp[i - 1][j - 1][k - 2][l - 1] + 1;
                                }
                            }
                        }
                    }
                    if (k >= 4) {
                        if (cur > dp[i - 1][j][k - 4][l]) {
                            cur = dp[i - 1][j][k - 4][l];
                        }
                    }
                    if (k >= 1) {
                        if (l >= 2) {
                            if (cur > dp[i - 1][j][k - 1][l - 2] + 11) {
                                cur = dp[i - 1][j][k - 1][l - 2] + 11;
                            }
                        }
                    }
                    if (l >= 3) {
                        if (cur > dp[i - 1][j][k][l - 3] + 9) {
                            cur = dp[i - 1][j][k][l - 3] + 9;
                        }
                    }
                }
            }
        }
    }
    cout << dp[60][50][100][80] << '\n';
    return 0;
}