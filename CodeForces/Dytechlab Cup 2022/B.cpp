#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lsqrt (ll x) {
    ll l = 1, r = 1000000000ll;
    while (l < r) {
        ll mid = l + r + 1 >> 1;
        if (mid * mid <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

void work () {
    ll l, r;
    cin >> l >> r;
    ll res = 0;
    ll lp = lsqrt(l), rp = lsqrt(r);
    if (rp - lp >= 1) {
        res += (rp - lp - 1) * 3;
        res += (((lp + 1) * (lp + 1) - 1) - l) / lp + 1;
        res += (r - rp * rp) / rp + 1;
    } else {
        if (l == r) {
            res += (l % lp == 0);
        } else {
            ll mid = (lp + 1) * lp;
            if (mid >= l && mid <= r) {
                res++;
            }
            if (l != mid && l % lp == 0) {
                res++;
            }
            if (r != mid && r % lp == 0) {
                res++;
            }
        }
    }
    cout << res << '\n';
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}