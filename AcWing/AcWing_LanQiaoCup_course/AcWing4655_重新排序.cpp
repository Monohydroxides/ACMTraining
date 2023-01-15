#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int cnt[N], a[N];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        cnt[r + 1]--, cnt[l]++;
    }
    for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + cnt[i];
    long long ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        ans1 += (long long) a[i] * cnt[i];
        // cout << a[i] << " " << cnt[i] << '\n';
    }
    sort(a + 1, a + 1 + n);
    sort(cnt + 1, cnt + 1 + n);
    for (int i = 1; i <= n; i++)
        ans2 += (long long) a[i] * cnt[i];
    cout << ans2 - ans1 << '\n';
    return 0;
}
