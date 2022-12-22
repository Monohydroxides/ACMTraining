#include <bits/stdc++.h>
using namespace std;

int a[200010], b[200010];

void work() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int l = 1; l <= n; l++) {
        int tmpl = l;
        int r = l;
        while (r < n && a[r + 1] <= b[r + 1]) {
            r++;
        }
        while (l <= r) {
            if (b[tmpl] - a[l] >= 0) {
                cout << b[tmpl] - a[l] << ' ';
            } else {
                while (b[tmpl] - a[l] < 0) {
                    tmpl++;
                }
                cout << b[tmpl] - a[l] << ' '; 
            }
            l++;
        }
    }
    cout << '\n';
    vector<int> res(n);
    for (int l = n; l >= 1; l--) {
        int r = l;
        while (r > 1 && a[r] <= b[r - 1]) {
            r--;
        }
        int tmpr = r;
        while (tmpr <= l) {
            res[tmpr - 1] = b[l] - a[tmpr];
            tmpr++;
        }
        l = r;
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}