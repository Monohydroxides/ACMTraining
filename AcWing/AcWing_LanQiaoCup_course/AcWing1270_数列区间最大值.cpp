#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N];

struct node {
    int l, r;
    int mx;
} tr[N << 2];

void pushup (int u) {
    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}

void build (int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].mx = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].mx;
    } 
    int mid = tr[u].l + tr[u].r >> 1;
    int res = INT_MIN;
    if (mid >= l) res = max(res, query(u << 1, l, r));
    if (mid < r)  res = max(res, query(u << 1 | 1, l, r));
    return res;
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, l, r) << '\n';
    }
    return 0;
}