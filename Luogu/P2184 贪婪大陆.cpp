#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;

struct node {
    int l, r;
    int cntl, cntr;
} tr[N << 2];

void pushup (int u) {
    tr[u].cntl = tr[u << 1].cntl + tr[u << 1 | 1].cntl;
    tr[u].cntr = tr[u << 1].cntr + tr[u << 1 | 1].cntr;
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

void modify (int u, int x, int val) {
    if (tr[u].l == tr[u].r) {
        if (val == 1)
            tr[u].cntl += 1;
        else
            tr[u].cntr += 1;
        return;
    }
    int mid = tr[u].r + tr[u].l >> 1;
    if (mid >= x) modify(u << 1, x, val);
    else          modify(u << 1 | 1, x, val);
    pushup(u);
}

int query (int u, int l, int r, int ty) {
    if (tr[u].l >= l && tr[u].r <= r) {
        if (ty == 1) return tr[u].cntl;
        else return tr[u].cntr;
    }
    int res = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= l)
        res += query(u << 1, l, r, ty);
    if (mid < r)
        res += query(u << 1 | 1, l, r, ty);
    return res;
}

int main () {
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            modify(1, l, 1);
            modify(1, r, 2);
        } else if (op == 2) {
            cout << query(1, 1, r, 1) - query(1, 1, l - 1, 2) << '\n';
        }
    }
    return 0;
}