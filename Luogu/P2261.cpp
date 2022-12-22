#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, k;
    cin >> n >> k;
    long long res = n * k;
    for (long long l = 1, r; l <= n; l = r + 1) {
        if (k / l != 0) {
            r = min(n, k / (k / l));
        } else {
            r = n;
        }
        // cout << l << " " << r << '\n';
        res -= (l * (k / l) + r * (k / l)) * (r - l + 1) / 2;
    }
    cout << res << '\n';
    return 0;
}