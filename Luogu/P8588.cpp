#include <bits/stdc++.h>
using namespace std;

long long n, k;

int main () {
    cin >> n >> k;
    long long cur = -1;
    for (long long i = 1; i <= k; ++i) {
        if (n == 1) {
            cur = k - i + 1;
            break;
        }
        n++;
        if (n % 3 == 0) {
            n /= 3;
        }
    }
    if (cur != -1) {
        if (cur % 2 == 0) {
            cout << 1 << '\n';
        } else if (cur % 2 == 1) {
            cout << 2 << '\n';
        }
    } else {
        cout << n << '\n';
    }
    return 0;
}