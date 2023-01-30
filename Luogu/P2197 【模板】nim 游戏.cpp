#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        res ^= (x);
    }
    if (!res) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
    }
    return;
}


int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}