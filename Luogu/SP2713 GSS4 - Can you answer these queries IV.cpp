#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
long long a[N];

struct node {
    int l, r;
    int tag;
    long long sum;
} tr[N << 2];

void pushup (int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].tag = tr[u << 1].tag && tr[u << 1 | 1].tag;
}

void build (int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].sum = a[l];
        tr[u].tag = a[l] == 0 || a[l] == 1;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify (int u, int l, int r) {
    if (tr[u].l == tr[u].r) {
        tr[u].sum = sqrtl(tr[u].sum);
        if (tr[u].sum == 0 || tr[u].sum == 1)
            tr[u].tag = 1;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid && !tr[u << 1].tag)       modify(u << 1, l, r);
    if (mid < r && !tr[u << 1 | 1].tag)    modify(u << 1 | 1, l, r);
    pushup(u);
}

long long query (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum;
    }
    long long res = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) res += query(u << 1, l, r);
    if (mid < r)  res += query(u << 1 | 1, l, r);
    return res;
}

int main () {
    int Case = 1;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        build(1, 1, n);
        scanf("%d", &m);
        printf("Case #%d:\n", Case);
        for (int i = 1; i <= m; i++) {
            int op, x, y;
            scanf("%d%d%d", &op, &x, &y);
            if (x > y) swap(x, y);
            if (op == 0)
                modify(1, x, y);
            else
                printf("%lld\n", query(1, x, y));
        }
        puts("");
        Case++;
    }
    return 0;
}