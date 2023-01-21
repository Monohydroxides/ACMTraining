#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N];

struct node {
    int l, r;
    int mx, mn;
} tr[N << 2];

void pushup (int u) {
    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
}

void build (int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].mx = a[l];
        tr[u].mn = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].mn;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 1e9;
    if (mid >= l)
        res = min(res, query(u << 1, l, r));
    if (mid < r)
        res = min(res, query(u << 1 | 1, l, r));
    return res;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(1, a, b) << ' ';
    }
    return 0;
} 