#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;

long long work (long long x) {
    long long res = 0;
    for (long long l = 1, r; l <= x; l = r + 1) {
        r = (x / (x / l));
        // cout << l << " " << r << '\n';
        res = (res + (r - l + 1) * (x / l) % P) % P;
    }
    return res;
}

int main () {
    long long l, r;
    cin >> l >> r;
    cout << (work(r) - work(l - 1) + P) % P << '\n';
    return 0;
}