#include <bits/stdc++.h>
using namespace std;

int n, m, h, tot;
int s[1010];

long double Comb (int a, int b) {
    long double ans = 1;
    for (int i = 1; i <= b; i++) {
        ans = ans * ((long double) a - i + 1) / i;
    }
    return ans;
}

int main () {
    cin >> n >> m >> h;
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
        tot += s[i];
    }
    if (tot < n) {
        cout << -1 << '\n';
        return 0;
    }
    long double prob = 1.0 - Comb(tot - s[h], n - 1) / Comb(tot - 1, n - 1);
    cout << fixed << setprecision(8) << prob << '\n';
    return 0;
}