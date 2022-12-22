#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main() {
    cin >> n >> a >> b;

    if (n == 1) {
        cout << (a == b) << "\n";
        cout << a << ":" << b << "\n";
        return 0;
    }

    int aw = min(a, n - (b != 0));
    int bw = min(b, n - aw);
    int draw = n - aw - bw;
    cout << draw << "\n";
    for (int i = 1; i <= draw; i++) {
        cout << "0:0\n";
    }
    for (int i = 1; i <= aw; i++) {
        cout << (i < aw ? 1 : a - (aw - 1)) << ":0\n";
    }
    for (int i = 1; i <= bw; i++) {
        cout << "0:" << (i < bw ? 1 : b - (bw - 1)) << "\n";
    }
    return 0;
}