#include <bits/stdc++.h>
using namespace std;

int n, k, t, x1, yx, x2, y2;

int main () {
    cin >> n >> k >> t >> x1 >> yx >> x2 >> y2;
    int res1 = 0, res2 = 0;
    while (n--) {
        bool r1 = false, r2 = false;
        int s = 0;
        for (int i = 0; i < t; i++) {
            int x, y;
            cin >> x >> y;
            if (x >= x1 && x <= x2 && y >= yx && y <= y2) {
                s++;
                r1 = true;
                if (s >= k) {
                    r2 = true;
                }
            } else {
                s = 0;
            }
        }
        if (r1) {
            res1++;
        }
        if (r2) {
            res2++;
        }
    }
    cout << res1 << '\n';
    cout << res2 << '\n';
    return 0;
}