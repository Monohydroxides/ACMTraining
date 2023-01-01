#include <bits/stdc++.h>
using namespace std;
 
int n, x;
int h[100010];
 
bool check (int val) {
    int cap = 0;
    for (int i = 1; i <= min(n - 1, val); ++i) {
        cap += h[i];
    }
    if (cap < 2 * x) {
        return false;
    }
    for (int i = val + 1; i <= n - 1; ++i) {
        cap -= h[i - val];
        cap += h[i];
        if (cap < 2 * x) {
            return false;
        }
    }
    return cap >= 2 * x;
}
 
int main () {
    cin >> n >> x;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> h[i];
    }
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << '\n';
    return 0;
}