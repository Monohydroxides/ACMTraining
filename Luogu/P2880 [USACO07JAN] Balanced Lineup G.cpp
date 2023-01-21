#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

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

pair<int, int> query (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return {tr[u].mx, tr[u].mn};
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pair<int, int> res = {-0x3f3f3f3f, 0x3f3f3f3f};
    if (mid >= l) {
        auto ret = query(u << 1, l, r);
        res.first = max(res.first, ret.first);
        res.second = min(res.second, ret.second);
    }
    if (mid < r) {
        auto ret = query(u << 1 | 1, l, r);
        res.first = max(res.first, ret.first);
        res.second = min(res.second, ret.second);
    }
    return res;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        auto ret = query(1, a, b);
        cout << ret.first - ret.second << '\n';
    }
    return 0;
} 