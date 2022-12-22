#include <bits/stdc++.h>
using namespace std;

int main () {
    long long p, q;
    cin >> p >> q;
    if (p != q) {
        cout << (p - 1) / 2 * (q - 1) / 2 << '\n';
    } else {
        cout << (p - 1) / 2 * (q - 1) / 2 + (p - 1) / 2 << '\n';
    }
    return 0;
}