#include <bits/stdc++.h>
using namespace std;

long double m, n;

int main () {
    cin >> m >> n;
    long double ans = 0;
    for (int p = 1; p <= m; p++) {
        ans += p * (pow(p / m, n) - pow((p - 1) / m, n));
    }
    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}
