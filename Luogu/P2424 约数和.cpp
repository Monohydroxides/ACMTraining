#include <bits/stdc++.h>
using namespace std;

long long work (int n) {
    long long res = 0;
    for (long long l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        // cout << l << " " << r << '\n';
        res = res + (long long) (n / l) * (l + r) * (r - l + 1) / 2;
    }
    return res;
}

int main () {
    long long x, y;
    cin >> x >> y;
    cout << work(y) - work(x - 1) << '\n';
    return 0;
}