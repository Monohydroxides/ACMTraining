#include <bits/stdc++.h>
using namespace std;

long long gcd (long long a, long long b) {
    return b == 0? a: gcd(b, a % b);
}

int main () {
    long long a, b;
    cin >> a >> b;
    int res = 0;
    long long dri = a * b;
    for (long long i = 1; i <= sqrt(dri); ++i) {
        if (i * i == dri && i == a) {
            res += 1;
            break;
        }
        if (dri % i == 0) {
            if (gcd(i, dri / i) == a) {
                res += 2;
            }
        }
    }
    cout << res << '\n';
    return 0;
}