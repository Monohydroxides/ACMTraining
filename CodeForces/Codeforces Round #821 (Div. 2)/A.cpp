#include <bits/stdc++.h>
using namespace std;

int arr[110];

void work () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    long long res = 0;
    for (int i = 1; i <= k; ++i) {
        int maxn = -1;
        for (int j = i; j <= n; j += k) {
            maxn = max(maxn, arr[j]);
        }
        // cout << maxn << ' ';
        res += maxn;
    }
    // cout << endl;
    cout << res << '\n';
    return;
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