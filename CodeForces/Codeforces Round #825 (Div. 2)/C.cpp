#include <bits/stdc++.h>
using namespace std;

int a[200010];

void work () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long res = 0;
    int l = 1, r = 1;
    while (l <= n) {
        while (r <= n && a[r] >= r - l + 1) {
            ++r;
        }
        long long sz = r - l;
        // cout << sz << " ";
        res += sz;
        l++;
    }
    // cout << '\n';
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