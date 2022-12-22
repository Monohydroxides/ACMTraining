#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 1;
    while (l <= n && a[l] == 0) {
        l++;
    }
    int r = n;
    while (r >= 1 && a[r] == 1) {
        r--;
    }
    int res = 0;
    while (l < r) {
        if (a[l] == 1) {
            l++;
            res++;
            r--;
            while (r > l && a[r] == 1) {
                r--;
            }
        } else {
            l++;
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