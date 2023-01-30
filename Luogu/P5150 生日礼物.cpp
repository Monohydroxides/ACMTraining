#include <bits/stdc++.h>
using namespace std;

long long n;

int main () {
    cin >> n;
    long long res = 1;
    for (long long i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            res = res * (2 * cnt + 1);
        }
    }
    if (n > 1) {
        res *= 3;
    }
    cout << res << '\n';
    return 0;
}