#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010];
long long pre[200010];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    if (pre[n] % 3) {
        cout << 0 << "\n";
        return 0;
    }
    long long par = pre[n] / 3;
    long long cnt = 0, ans = 0;
    for (int i = 1; i < n; i++) {
        if (pre[i] == 2 * par) ans += cnt;
        if (pre[i] == par) cnt++;
    }
    cout << ans << "\n";
    return 0;
}