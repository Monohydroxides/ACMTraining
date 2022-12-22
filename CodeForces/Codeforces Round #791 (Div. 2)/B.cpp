#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define all(a) ((a).begin(), (a).end())
#define debug(a) cout << "Debug: " << #a << ": " << a << "\n"
#define per(i, a, b, c) for (int i = a; i < b; i += c)
#define pere(i, a, b, c) for (int i = a; i <= b; i += c)
#define rep(i, a, b, c) for (int i = a; i > b; i -= c)
#define repe(i, a, b, c) for (int i = a; i >= b; i -= c)
#define mst(a, x) memset(a, x, sizeof a)

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 998244353;

int T;

int n, q;
int a[200010];
LL sum;

struct node {
    int l, r;
    LL sum, add;
    int vaild;
} tr[200010 * 4];

void pushup(int u) { tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum; }

void pushdown(int u) {
    node &rot = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
    l.sum = rot.add * (l.r - l.l + 1), l.add = rot.add;
    r.sum = rot.add * (r.r - r.l + 1), r.add = rot.add;
    rot.add = 0;
    rot.vaild = 0;
    l.vaild = 1, r.vaild = 1;
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, a[l], 0, 0};
    } else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, LL v) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum = (tr[u].r - tr[u].l + 1) * v;
        tr[u].add = v;
        tr[u].vaild = 1;
    } else {
        if (tr[u].vaild)
            pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (mid >= l)
            modify(u << 1, l, r, v);
        if (mid < r)
            modify(u << 1 | 1, l, r, v);
        // tr[u].vaild = 1;
        pushup(u);
    }
}

LL query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        if (tr[u].vaild)
            pushdown(u);
        return tr[u].sum;
    }
    if (tr[u].vaild)
        pushdown(u);
    LL sum = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= l)
        sum += query(u << 1, l, r);
    if (mid < r)
        sum += query(u << 1 | 1, l, r);
    return sum;
}

void work() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            modify(1, p, p, x);
            cout << query(1, 1, n) << endl;
        } else {
            int x;
            cin >> x;
            modify(1, 1, n, x);
            cout << query(1, 1, n) << endl;
        }
        // for (int i = 1; i <= n; ++i) {
        //     cout << query(1, i, i) << " ";
        // }
        // cout << endl;
    }
}

int main() {
    cin.tie(0);
    T = 1;
    while (T--)
        work();
    return 0;
}