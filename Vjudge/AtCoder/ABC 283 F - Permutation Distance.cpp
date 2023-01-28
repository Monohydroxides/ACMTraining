#include <bits/stdc++.h>
using namespace std;

const int N = 400010, inf = 0x3f3f3f3f;

int n;
int a[N], ans[N];

struct node {
    int l, r;
    int maxval, minval;
} tr[N << 2];

void pushup (int u) {
    tr[u].maxval = max(tr[u << 1].maxval, tr[u << 1 | 1].maxval);
    tr[u].minval = min(tr[u << 1].minval, tr[u << 1 | 1].minval);
}

void build (int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].maxval = -inf;
        tr[u].minval = inf;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify (int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].maxval = max(tr[u].maxval, v);
        tr[u].minval = min(tr[u].minval, v);
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= x) modify(u << 1, x, v);
    else modify(u << 1 | 1, x, v);
    pushup(u);
}

int query (int u, int l, int r, int type) {
    if (tr[u].l >= l && r >= tr[u].r) {
        return type == 1 ? tr[u].maxval : tr[u].minval;
    }
    int res = type == 1 ? -inf : inf;
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= l) res = type == 1 ? max(res, query(u << 1, l, r, type)) : min(res, query(u << 1, l, r, type));
    if (mid < r)  res = type == 1 ? max(res, query(u << 1 | 1, l, r, type)) : min(res, query(u << 1 | 1, l, r, type));
    return res;
}

void clear (int u, int l, int r) {
    if (tr[u].l < l || tr[u].r > r) return;
    tr[u].maxval = -inf, tr[u].minval = inf;
    clear(u << 1, l, r);
    clear(u << 1 | 1, l, r);
} 

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[i] = inf;
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        // cout << "qry1 " << i << " " << a[i] << ' ' << a[i] + i - query(1, 1, a[i] - 1, 1) << '\n';
        ans[i] = min(ans[i], a[i] + i - query(1, 1, a[i] - 1, 1));
        modify(1, a[i], a[i] + i);
    }
    clear(1, 1, n);
    for (int i = n; i >= 1; i--) {
        // cout << "qry2 " << i << " " << a[i] << ' ' << query(1, a[i] + 1, n, -1) - a[i] - i << '\n';
        ans[i] = min(ans[i], query(1, a[i] + 1, n, -1) - a[i] - i);
        modify(1, a[i], a[i] + i);
        // cout << ans[i] << " ";
    }
    // cout << '\n';
    clear(1, 1, n);
    for (int i = 1; i <= n; i++) {
        ans[i] = min(ans[i], query(1, a[i] + 1, n, -1) - a[i] + i);
        modify(1, a[i], a[i] - i);
        // cout << ans[i] << " ";
    }
    // cout << '\n';
    clear(1, 1, n);
    for (int i = n; i >= 1; i--) {
        ans[i] = min(ans[i], a[i] - i - query(1, 1, a[i] - 1, 1));
        modify(1, a[i], a[i] - i);
        // cout << ans[i] << " ";
    }
    // cout << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}