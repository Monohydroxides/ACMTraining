#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int cnt[100010];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int cur = min(i, n - i + 1);
        cur = a[i] - cur;
        if (cur >= 0) {
            cnt[cur]++;
            mx = max(mx, cnt[cur]);
        }
    }
    cout << n - mx << '\n';
    return 0;
}