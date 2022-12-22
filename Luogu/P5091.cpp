#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int qmi (int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (ll) res * a % p;
        }
        a = (ll) a * a % p;
        b >>= 1;
    }
    return res;
}

int main () {
    int a, m;
    string b;
    cin >> a >> m >> b;
    ll bb = 0, phim = m;
    int tmp = m;
    for (int i = 2; i <= m / i; ++i) {
        if (tmp % i == 0) {
            phim = phim - phim / i;
            while (tmp % i == 0) {
                tmp /= i;
            }
        }
    }
    if (tmp > 1) {
        phim = phim - phim / tmp;
    }

    int flg = 0;
    for (int i = 0; i < b.size(); ++i) {
        bb = ((ll) bb * 10 + (b[i] - '0'));
        if (bb >= phim) {
            flg = 1;
        }
        bb %= phim;
    }
    if (flg) {
        cout << qmi(a, bb + phim, m) << endl;
    } else {
        cout << qmi(a, bb, m) << endl;
    }
    return 0;
}