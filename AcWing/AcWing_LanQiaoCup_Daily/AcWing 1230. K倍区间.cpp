#include <bits/stdc++.h>
using namespace std;

int n, k;
long long ans;
int a[100010];
int pre[100010];
int cnt[100010];

int main () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = (pre[i - 1] + a[i]) % k;
        ans += cnt[pre[i]];
        cnt[pre[i]]++;
    }
    cout << ans + cnt[0] << "\n";
    return 0;
}
