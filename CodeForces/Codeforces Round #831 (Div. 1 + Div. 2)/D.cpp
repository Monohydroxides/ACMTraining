#include <bits/stdc++.h>
using namespace std;

void work () {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> mp;
    int cur = k, usd = 0;
    int flg = 0;
    for (int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        mp[x]++;
        if (flg != 0) {
            continue;
        }
        if (x == cur) {
            cur--;
            while (cur > 0 && mp.count(cur) && mp[cur]) {
                mp[cur] = 0;
                cur--;
                usd--;
            }
        } else {
            usd++;
        }
        if (usd > (n * m - 4)) {
            flg = -1;
        }
    }
    if (flg == -1) {
        cout << "TIDAK\n";
    } else {
        cout << "YA\n";
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