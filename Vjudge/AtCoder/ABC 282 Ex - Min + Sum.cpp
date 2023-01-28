#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

long long n, s, ans;
long long lg2[N], a[N];
long long b[N];
struct rmq {
    long long val;
    long long id;
    rmq operator* (const rmq& rhs) const {
        if (val > rhs.val) {
            return rhs;
        }
        return *this;
    }
} st[N][20];

rmq query (int l, int r) {
    int mid = lg2[r - l + 1];
    return st[l][mid] * st[r - (1 << mid) + 1][mid];
}

void work (int l, int r) {
    if (l > r) return;
    rmq cur = query(l, r);
    // cout << l << " " << r << '\n';
    int x = cur.id;
    if (x - l < r - x) {
        for (int ll = l; ll <= x; ll++) {
            // int lp = x, rp = r;
            // while (lp < rp) {
            //     int mid = lp + rp + 1 >> 1;
            //     if (b[mid] - b[ll - 1] + cur.val <= s) lp = mid;
            //     else rp = mid - 1;
            // }
            ans += upper_bound(b + x, b + r + 1, b[ll - 1] + s - cur.val) - b - x;
        }
    } else {
        for (int rr = x; rr <= r; rr++) {
            // int lp = l, rp = x;
            // while (lp < rp) {
            //     int mid = lp + rp >> 1;
            //     if (b[rr] - b[mid - 1] + cur.val <= s) rp = mid;
            //     else lp = mid + 1;
            // }
            ans += x - (lower_bound(b + l - 1, b + x, b[rr] - s + cur.val) - b + 1) + 1;
        }
    }
    work(l, x - 1);
    work(x + 1, r);
}

int main () {
    cin >> n >> s;
    for (int i = 2; i <= n; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st[i][0] = {a[i], i};
    }
    for (int i = 1; i <= lg2[n]; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st[j][i] = st[j][i - 1] * st[j + (1 << i - 1)][i - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    work(1, n);
    cout << ans << '\n';
    return 0;
}
