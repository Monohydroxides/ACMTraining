#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n;
string str1, str2;
int dp[100010][4];

int add (int a, int b) {
    return (a + b) % mod;
}

int mul (int a, int b) {
    return (long long) a * b % mod;
}

int sub (int a, int b) {
    return ((a - b) % mod + mod) % mod; 
}


int main () {
    cin >> n;
    cin >> str1 >> str2;
    str1 = " " + str1, str2 = " " + str2;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (str1[i] != '?' && str2[i] != '?') {
            if (str1[i] == str2[i]) {
                for (int k = 0; k < 4; ++k) dp[i][k] = dp[i - 1][k];
            } else if (str1[i] > str2[i]) {
                dp[i][0] = 0;
                dp[i][1] = add(dp[i - 1][1], dp[i - 1][0]);
                dp[i][2] = 0;
                dp[i][3] = add(dp[i - 1][2], dp[i - 1][3]);
            } else {
                dp[i][0] = 0;
                dp[i][1] = 0;
                dp[i][2] = add(dp[i - 1][2], dp[i - 1][0]);
                dp[i][3] = add(dp[i - 1][1], dp[i - 1][3]);
            }
        } else {
            if (str1[i] == '?' && str2[i] == '?') {
                for (int r = '0'; r <= '9'; ++r) {
                    for (int s = '0'; s <= '9'; ++s) {
                        if (r == s) {
                            for (int k = 0; k < 4; ++k) dp[i][k] = add(dp[i][k], dp[i - 1][k]);
                        } else if (r > s) {
                            dp[i][1] = add(dp[i][1], add(dp[i - 1][1], dp[i - 1][0]));
                            dp[i][3] = add(dp[i][3], add(dp[i - 1][2], dp[i - 1][3]));
                        } else {
                            dp[i][2] = add(dp[i][2], add(dp[i - 1][2], dp[i - 1][0]));
                            dp[i][3] = add(dp[i][3], add(dp[i - 1][1], dp[i - 1][3]));
                        }
                    } 
                }
            } else if (str1[i] == '?') {
                for (int r = '0'; r <= '9'; ++r) {
                    if (r == str2[i]) {
                        for (int k = 0; k < 4; ++k) dp[i][k] = add(dp[i][k], dp[i - 1][k]);
                    } else if (r > str2[i]) {
                        dp[i][1] = add(dp[i][1], add(dp[i - 1][1], dp[i - 1][0]));
                        dp[i][3] = add(dp[i][3], add(dp[i - 1][2], dp[i - 1][3]));
                    } else {
                        dp[i][2] = add(dp[i][2], add(dp[i - 1][2], dp[i - 1][0]));
                        dp[i][3] = add(dp[i][3], add(dp[i - 1][1], dp[i - 1][3]));
                    }
                }
            } else {
                for (int r = '0'; r <= '9'; ++r) {
                    if (r == str1[i]) {
                        for (int k = 0; k < 4; ++k) dp[i][k] = add(dp[i][k], dp[i - 1][k]);
                    } else if (r < str1[i]) {
                        dp[i][1] = add(dp[i][1], add(dp[i - 1][1], dp[i - 1][0]));
                        dp[i][3] = add(dp[i][3], add(dp[i - 1][2], dp[i - 1][3]));
                    } else {
                        dp[i][2] = add(dp[i][2], add(dp[i - 1][2], dp[i - 1][0]));
                        dp[i][3] = add(dp[i][3], add(dp[i - 1][1], dp[i - 1][3]));
                    }
                }
            }
        }
    }
    cout << dp[n][3] << '\n';
    return 0;
}