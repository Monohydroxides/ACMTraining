#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
long long a[N];

struct node {
    int l, r;
    long long tagv;
    long long sum;
} tr[N << 2];

void pushup (int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown (int u) {
    if (tr[u].tagv) {
        tr[u << 1].tagv += tr[u].tagv;
        tr[u << 1 | 1].tagv += tr[u].tagv;
        tr[u << 1].sum += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].tagv;
        tr[u << 1 | 1].sum += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].tagv;
        tr[u].tagv = 0;
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

void modify (int u, int l, int r, long long val) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * val;
        tr[u].tagv += val;
        return;
    }
    pushdown(u);
    int mid = tr[u].r + tr[u].l >> 1;
    if (mid >= l) modify(u << 1, l, r, val);
    if (mid < r)  modify(u << 1 | 1, l, r, val);
    pushup(u);
}

long long query (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum;
    }
    pushdown(u);
    int mid = tr[u].r + tr[u].l >> 1;
    long long res = 0;
    if (mid >= l) res += query(u << 1, l, r);
    if (mid < r)  res += query(u << 1 | 1, l, r);
    return res;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            long long k, d;
            cin >> l >> r >> k >> d;
            modify(1, l, l, k);
            if (r > l)
                modify(1, l + 1, r, d);
            if (r + 1 <= n)
                modify(1, r + 1, r + 1, -(k + (r - l) * d));
        } else {
            int q;
            cin >> q;
            cout << a[q] + query(1, 1, q) << '\n';
        }
    }
    return 0;
}