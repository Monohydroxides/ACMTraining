#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

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

void modify (int u, int x, int v) {
    if (tr[u].l == tr[u].r && tr[u].l == x) {
        if (tr[u].mx < v) tr[u].mx = v;
        return; 
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= x) modify(u << 1, x, v);
    else modify(u << 1 | 1, x, v);
    pushup(u);
}

int query (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].mx;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (mid >= l) res = max(res, query(u << 1, l, r));
    if (mid < r)  res = max(res, query(u << 1 | 1, l, r));
    return res;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "Q")
            cout << query(1, a, b) << '\n';
        else 
            modify(1, a, b);
    }
    return 0;
} 