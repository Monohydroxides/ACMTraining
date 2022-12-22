#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    map<int, int> cntbit, cntzro;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (int cnt = 1; cnt <= 11; ++cnt) {
            if (x & 1) {
                cntbit[cnt]++;
            } else {
                cntzro[cnt]++;
            }
            x >>= 1;
        }
    }
    int res = 0;
    for (int i = 1; i <= 11; ++i) {
        if (cntbit[i] && cntzro[i]) {
            res += 1 << (i - 1);
        }
    }
    cout << res << '\n';
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