#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;

struct node {
    int l, r;
    int bit;
    int rtag;
} tr[N << 2];

void pushdown (int u) {
    if (tr[u].rtag) {
        if (tr[u].l != tr[u].r) {
            tr[u << 1].rtag ^= 1;
            tr[u << 1 | 1].rtag ^= 1;
        }
        tr[u].bit ^= 1;
        tr[u].rtag = 0;
    }
}

void build (int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void modify (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].rtag ^= 1;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= l) modify(u << 1, l, r);
    if (mid < r)  modify(u << 1 | 1, l, r);
}

int query (int u, int x) {
    if (tr[u].l == tr[u].r) {
        if (tr[u].rtag) {
            tr[u].bit ^= 1;
            tr[u].rtag = 0;
        }
        return tr[u].bit;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= x) return query(u << 1, x);
    else  return query(u << 1 | 1, x);
}

int main () {
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            modify(1, l, r);
        } else {
            int x;
            cin >> x;
            cout << query(1, x) << '\n';
        }
    }
    return 0;
} 