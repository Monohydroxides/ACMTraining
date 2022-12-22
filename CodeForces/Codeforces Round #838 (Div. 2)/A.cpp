#include <bits/stdc++.h>
using namespace std;

int a[55];

void work () {
    int n;
    cin >> n;
    int sum = 0;
    int minn = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];

        int tmp = a[i];
        int cnt = 0;
        while ((tmp & 1) == (a[i] & 1)) {
            tmp >>= 1;
            cnt += 1;
        }
        minn = min(minn, cnt);
        sum += a[i];
    }
    if (sum & 1) {
        cout << minn << '\n';
    } else {
        cout << 0 << '\n';
    }
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