#include <bits/stdc++.h>
using namespace std;

void work () {
    int a[2][2];
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
    int mx = min({a[0][0], a[0][1], a[1][0], a[1][1]});
    while (a[0][0] != mx) {
        int tmp = a[0][1];
        a[0][1] = a[0][0];
        a[0][0] = a[1][0];
        a[1][0] = a[1][1];
        a[1][1] = tmp;
    }
    if (a[0][0] < a[0][1] && a[0][0] < a[1][0] && a[1][0] < a[1][1] && a[0][1] < a[1][1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}