#include <bits/stdc++.h>
using namespace std;

int a[110], b[110];

void work () {
    int n;
    cin >> n;
    int cnta = 0, cntb = 0;
    int opt = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            cnta++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if (b[i] != a[i]) {
            opt++;
        }
        if (b[i] == 1) {
            cntb++;
        }
    }
    if (cnta == cntb) {
        if (opt) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    } else {
        int res = abs(cnta - cntb);
        opt -= res;
        if (opt) {
            res += 1;
        }
        cout << res << '\n';
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