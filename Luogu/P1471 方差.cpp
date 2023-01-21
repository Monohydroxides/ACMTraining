
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const double eps = 1e-6;

int n, m;
double a[N];

struct node {
    int l, r;
    double tagv;
    double sum;
    double sum2;
} tr[N << 2];

void pushup (int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].sum2 = tr[u << 1].sum2 + tr[u << 1 | 1].sum2;
}

void pushdown (int u) {
    if (fabs(tr[u].tagv) > eps) {
        tr[u << 1].tagv += tr[u].tagv;
        tr[u << 1 | 1].tagv += tr[u].tagv;

        tr[u << 1].sum2 += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].tagv * tr[u].tagv + 2 * tr[u << 1].sum * tr[u].tagv;
        tr[u << 1 | 1].sum2 += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].tagv * tr[u].tagv + 2 * tr[u << 1 | 1].sum * tr[u].tagv;

        tr[u << 1].sum += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].tagv;
        tr[u << 1 | 1].sum += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].tagv;

        tr[u].tagv = 0;
    } 
}

void build (int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].sum = a[l];
        tr[u].sum2 = a[l] * a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify (int u, int l, int r, double val) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum2 += (tr[u].r - tr[u].l + 1) * val * val + 2 * tr[u].sum * val;
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

pair<double, double> query (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return {tr[u].sum, tr[u].sum2};
    }
    pushdown(u);
    int mid = tr[u].r + tr[u].l >> 1;
    pair<double, double> res = {0, 0};
    if (mid >= l) {
        auto ret = query(u << 1, l, r);
        res.first += ret.first;
        res.second += ret.second;
    }
    if (mid < r) {
        auto ret = query(u << 1 | 1, l, r);
        res.first += ret.first;
        res.second += ret.second;
    }
    return res;
}

int main () {
    cin >> n >> m;
    cout << fixed << setprecision(4);
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            double k;
            cin >> k;
            modify(1, l, r, k);
        } else if (op == 2) {
            cout << query(1, l, r).first / (r - l + 1.0) << '\n';
        } else {
            auto ret = query(1, l, r);
            // cout << ret.second << " " << ret.first << '\n';
            cout << ret.second / (r - l + 1.0) - (ret.first / (r - l + 1.0)) * (ret.first / (r - l + 1.0)) << '\n';
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << query(1, i, i).second << '\n';
    // }
    return 0;
}