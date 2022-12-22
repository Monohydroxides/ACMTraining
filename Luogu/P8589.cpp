#include <bits/stdc++.h>
using namespace std;

int n;

int main () {
    cin >> n;
    if (n % 4 != 1) {
        cout << -1 << '\n';
    } else {
        cout << 0;
        for (int i = 1; i <= n / 4; ++i) {
            cout << "0110";
        }
        cout << '\n';
    }
    return 0;
}