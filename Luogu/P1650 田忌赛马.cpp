#include <bits/stdc++.h>
using namespace std;

int n;
int a[2010], b[2010];

int main () {
    cin >> n;
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
    int res = 0;
    int l = 1, r = n, s = 1, k = n;
    for (int i = 1; i <= n; ++i) {
        if (a[r] > b[k]) {
            r--, k--;
            res += 200;
        } else if (a[l] > b[s]) {
            l++, s++;
            res += 200;
        } else if (a[l] < b[k]) {
            l++, k--;
            res -= 200;
        }
    }
    cout << res << '\n';
    return 0;
}