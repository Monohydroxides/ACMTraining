#include <bits/stdc++.h>
using namespace std;

typedef long long _int128;

int n, m;
int a[51][51];
pair<long long, long long> dp[55][55];

long long gcd (long long a, long long b) {
    return b == 0? a: gcd(b, a % b);
}

pair<long long, long long> mul (pair<long long, long long> a, pair<long long, long long> b) {
    a.first *= b.first;
    a.second *= b.second;
    long long g = gcd(a.first, a.second);
    if (!g) {
        return a;
    }
    a.first /= g;
    a.second /= g;
    return a;
}

pair<long long, long long> add (pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first == 0) {
        return b;
    } else if (b.first == 0) {
        return a;
    }
    long long g = gcd(a.second, b.second);
    a.first *= (b.second / g);
    a.first += b.first * (a.second / g);
    a.second *= (b.second / g);
    g = gcd(a.first, a.second);
    a.first /= g, a.second /= g;
    return a;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            char chr;
            while (cin >> chr) {
                if (chr == '*' || chr == '.') {
                    if (chr == '*') {
                        a[i][j] = 1;
                    } else {
                        a[i][j] = 0;
                    }
                    break;
                }
            }
        }
    }
    for (int j = 1; j <= n + 1; ++j) {
        a[n + 1][j] = 1;
    }
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = {0, 1};
        }
    }
    int stp = 1, stq = 1;
    while (stp <= n + 1 && !a[stp][stq]) {
        stp += 2, stq += 1;
    }
    dp[stp][stq] = {1, 1};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (!a[i + 1][j]) {
                int p = i + 1, q = j;
                while (p <= n + 1 && !a[p][q]) {
                    p += 2, q += 1;
                }
                dp[p][q] = add(dp[p][q], mul(dp[i][j], pair<long long, long long> {1, 2}));
            } else {
                dp[i + 1][j] = add(dp[i + 1][j], mul(dp[i][j], pair<long long, long long> {1, 2}));
            }
            if (!a[i + 1][j + 1]) {
                int p = i + 1, q = j + 1;
                while (p <= n + 1 && !a[p][q]) {
                    p += 2, q += 1;
                }
                dp[p][q] = add(dp[p][q], mul(dp[i][j], pair<long long, long long> {1, 2}));
            } else {
                dp[i + 1][j + 1] = add(dp[i + 1][j + 1], mul(dp[i][j], pair<long long, long long> {1, 2}));
            }
        }
    }
    cout << dp[n + 1][m + 1].first << '/' << dp[n + 1][m + 1].second << '\n';
    return 0;
}