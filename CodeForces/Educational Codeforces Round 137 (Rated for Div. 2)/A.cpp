#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
    }
    cout << (10 - n) * (9 - n) * 3 << '\n';
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