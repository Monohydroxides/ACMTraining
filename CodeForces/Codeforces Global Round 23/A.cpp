#include <bits/stdc++.h>
using namespace std;

void work () {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int flg = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i]) {
            flg = 1;
        }
    }
    if (flg) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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