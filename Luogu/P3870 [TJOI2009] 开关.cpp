#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;

struct node {
    int l, r;
    int cnt;
    int rtag;
} tr[N << 2];

void pushup (int u) {
    tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
}

void pushdown (int u) {
    if (tr[u].rtag) {
        tr[u << 1].cnt = tr[u << 1].r - tr[u << 1].l + 1 - tr[u << 1].cnt;
        tr[u << 1 | 1].cnt = tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1 - tr[u << 1 | 1].cnt;
        tr[u << 1].rtag ^= 1;
        tr[u << 1 | 1].rtag ^= 1;
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
        tr[u].cnt = tr[u].r - tr[u].l + 1 - tr[u].cnt;
        tr[u].rtag ^= 1;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= l) modify(u << 1, l, r);
    if (mid < r)  modify(u << 1 | 1, l, r);
    pushup(u);
}

int query (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].cnt;
    }
    pushdown(u);
    int mid = tr[u].r + tr[u].l >> 1;
    int res = 0;
    if (mid >= l) res += query(u << 1, l, r);
    if (mid < r)  res += query(u << 1 | 1, l, r);
    return res;
}

int main () {
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 0)
            modify(1, l, r);
        else 
            cout << query(1, l, r) << '\n';
    }
    return 0;
} 