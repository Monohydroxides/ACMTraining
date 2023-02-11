#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000010];
int ans[4];
int flg;

int main () {
    cin >> n;
    ans[1] = -0x3f3f3f3f;
    ans[2] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[1] = max(ans[1], a[i]);
        ans[2] = min(ans[2], a[i]);
    }
    if (n & 1) {
        ans[3] = a[n / 2 + 1];
    } else {
        if ((a[n / 2] + a[n / 2 + 1]) & 1) {
            flg = 1;
        }
        ans[3] = (a[n / 2] + a[n / 2 + 1]) / 2;
    }
    cout << ans[1] << " ";
    if (flg) {
        cout << fixed << setprecision(1);
        cout << ans[3] + (ans[3] < 0 ? -1 : 1) * (flg == 1 ? 0.5 : 0) << " ";
    } else {
        cout << ans[3] << " ";
    }
    cout << ans[2] << "\n";
    return 0;
}