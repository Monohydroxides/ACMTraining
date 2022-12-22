#include <bits/stdc++.h>
using namespace std;

void work (long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
        if (res > 1e9 || res <= 0) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << res << '\n';
}

int main () {
    long long a, b;
    cin >> a >> b;
    work(a, b);
    return 0;
}