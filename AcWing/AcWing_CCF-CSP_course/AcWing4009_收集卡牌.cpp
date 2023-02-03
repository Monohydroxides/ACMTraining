#include <bits/stdc++.h>
using namespace std;

int n, k;
double a[20];
double f[81][(1 << 16)];

int count (int x) {
    int res = 0;
    while (x) {
        if (x & 1) res++;
        x >>= 1;
    }
    return res;
}

double dp (int round, int coin, int state) {
    if (f[round][state]) return f[round][state];
    int card = count(state), left = n - card;
    if (coin >= k * left) return round;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        if ((state >> i) & 1) {
            ans += a[i] * dp(round + 1, coin + 1, state);
        } else {
            ans += a[i] * dp(round + 1, coin, state | (1 << i));
        }
    }
    return f[round][state] = ans;
}

int main () {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << fixed << setprecision(10) << dp(0, 0, 0) << "\n";
    return 0;
}