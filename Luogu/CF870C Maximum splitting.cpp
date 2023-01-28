#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    if (n <= 3 || n == 5 || n == 7 || n == 11) {
        cout << "-1\n";
        return;
    }
    cout << n / 4 - (n & 1) << '\n';
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}