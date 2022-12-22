#include <bits/stdc++.h>
using namespace std;

int n;
int res;
int a[262145];

void opt (int l, int r, int k) {
    if (l >= r) {
        return;
    }
    if (res == -1) {
        return;
    }
    int mid = l + r >> 1;
    int lmin, lmax, rmin, rmax;
    lmin = 0x3f3f3f3f, rmin = 0x3f3f3f3f, lmax = 0, rmax = 0;
    for (int i = l; i <= mid; ++i) {
        lmin = min(lmin, a[i]);
        lmax = max(lmax, a[i]);
    }
    for (int i = mid + 1; i <= r; ++i) {
        rmin = min(rmin, a[i]);
        rmax = max(rmax, a[i]);
    }
    if (lmin < rmax && lmax > rmin) {
        res = -1;
        return;
    }
    if (lmax > rmin && lmin < rmax) {
        res = -1;
        return;
    }
    if (lmin > rmax) {
        res++;
        for (int i = l; i <= mid; ++i) {
            swap(a[i], a[mid + i - l + 1]);
        }
    }
    opt(l, mid, k / 2), opt(mid + 1, r, k / 2);
}

void work () {
    cin >> n;
    res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    opt(1, n, n);
    cout << res << '\n';
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