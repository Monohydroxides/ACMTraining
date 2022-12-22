#include <bits/stdc++.h>
using namespace std;

long long phi (long long x) {
    long long res = x;
    for (long long i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            while (x % i == 0)  x /= i;
            res = res / i * (i - 1);
        }
    }
    if (x > 1) {
        res = res / x * (x - 1);
    }
    return res;
}

void work () {
    long long a, m;
    cin >> a >> m;
    long long d = __gcd(a, m);
    // cout << d << '\n';
    cout << phi(m / d) << '\n';
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}