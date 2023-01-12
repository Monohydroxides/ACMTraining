#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

int main () {
    double n, l, r;
    cin >> n;
    l = -10000.0, r = 10000.0;
    while (r - l > eps) {
        double mid = (r + l) / 2;
        if (mid * mid * mid > n) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(6) << l << '\n';
}