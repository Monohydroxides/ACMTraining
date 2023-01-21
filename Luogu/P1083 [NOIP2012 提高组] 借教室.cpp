#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m;
int a[N];

struct node {
    int l, r;
    int mn;
    int vtag;
} tr[N << 2];

void pushup (int u) {
    tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
}

void pushdown (int u) {
    if (tr[u].vtag) {
        tr[u << 1].mn += tr[u].vtag;
        tr[u << 1 | 1].mn += tr[u].vtag;
        tr[u << 1].vtag += tr[u].vtag;
        tr[u << 1 | 1].vtag += tr[u].vtag;
        tr[u].vtag = 0;
    }
}

void build (int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].mn = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify (int u, int l, int r, int val) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].mn += val;
        tr[u].vtag += val;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= l) modify(u << 1, l, r, val);
    if (mid < r)  modify(u << 1 | 1, l, r, val);
    pushup(u);
}

int query (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].mn;
    }
    pushdown(u);
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
        int a, b, c;
        cin >> a >> b >> c;
        if (query(1, b, c) < a) {
            cout << -1 << '\n';
            cout << i << '\n';
            return 0;
        } else {
            modify(1, b, c, -a);
        }
    }
    cout << 0 << '\n';
    return 0;
} 