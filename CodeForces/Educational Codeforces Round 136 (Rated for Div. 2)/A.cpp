#include <bits/stdc++.h>
using namespace std;

void work () {
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << "1 1\n";
    } else if (n <= 2 && m <= 2) {
        cout << "1 1\n";
    } else if (n <= 2 && m > 2) {
        cout << "2 2\n";
    } else if (n > 2 && m <= 2) {
        cout << "2 2\n";
    } else {
        cout << "2 2\n";
    }
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}