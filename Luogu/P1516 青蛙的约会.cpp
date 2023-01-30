#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exgcd (ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main () {
    ll x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    ll a = m - n;
    ll b = y - x;
    if (a < 0) {
        b = -b, a = -a;
    }
    ll xx = 0, yy = 0;
    ll d = exgcd(a, L, xx, yy);
    if (b % d != 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << ((xx * (b / d)) % (L / d) + (L / d)) % (L / d) << endl;
    return 0;
}