#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<long long> a, pre;

bool check (int x) {
    int ans = k;
    int l = 1;
    while (l <= n) {
        int r = l;
        while (r <= n && pre[r] - pre[l - 1] <= x) {
            r++;
        }
        ans--;
        l = r;
        if (ans < 0) return 0;
    }
    return 1;
}

int main () {
    cin >> n >> k;
    a.resize(n + 1), pre.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
    return 0;
}