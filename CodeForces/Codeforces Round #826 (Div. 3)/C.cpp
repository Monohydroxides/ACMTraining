#include <bits/stdc++.h>
using namespace std;

int n;
int a[2010];
long long sum[2010];

bool dfs (int u, int x, long long aim) {
    if (u > n) {
        return true;
    }
    if (sum[n] - sum[u - 1] < aim) {
        return false;
    }
    int l = u;
    for (int r = l; r <= min(n, l + x - 1); ++r) {
        if (l == 1) {
            if (dfs(r + 1, x, sum[r] - sum[l - 1])) {
                return true;
            }
        } else {
            if (sum[r] - sum[l - 1] == aim) {
                return dfs(r + 1, x, sum[r] - sum[l - 1]);
            }
        }
    }
    return false;
}

bool check (int x) {
    return dfs(1, x, 0);
}

void work () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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