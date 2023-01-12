#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

int n, res;
int a[N];
bool st[N];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int mx = -1, mn = 1e6;
        for (int j = i; j <= n; j++) {
            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
            if (j - i + 1 == mx - mn + 1) {
                // cout << i << " " << j << '\n';
                res++;
            }
        }
    }
    cout << res << '\n';
    return 0;
}