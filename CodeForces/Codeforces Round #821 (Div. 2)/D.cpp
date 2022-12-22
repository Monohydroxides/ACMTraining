#include <bits/stdc++.h>
using namespace std;

int dp[3010];

void work () {
    long long n, x, y;
    string stra, strb;
    cin >> n >> x >> y;
    cin >> stra >> strb;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (stra[i] != strb[i]) {
            pos.push_back(i);
        }
    }
    if (pos.size() % 2) {
        cout << -1 << '\n';
        return;
    }
    if (x >= y) {
        if (pos.size() == 2) {
            if (pos[1] - pos[0] == 1) {
                cout << min(x, 2 * y) << '\n';
            } else {
                cout << y << '\n';
            }
        } else {
            cout << pos.size() / 2 * y << '\n';
        }
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