#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int a[N];

struct node {
    int l, r;
    map<int, int> mp;
} tr[N << 2];

void build (int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].mp[a[l]] = 1;
        return;
    }
    for (int i = l; i <= r; ++i) {
        tr[u].mp[a[i]]++;
    }
    int mid = l + r >> 1;
    build (u << 1, l, mid), build (u << 1 | 1, mid + 1, r);
}

void modify (int u, int l, int r, int k) {
    if (tr[u].l == tr[u].r) {
        tr[u].mp[k]--;
        tr[u].mp[r]++;
        return;
    }
    tr[u].mp[k]--;
    tr[u].mp[r]++;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)   modify (u << 1, l, r, k);
    else            modify (u << 1 | 1, l, r, k);
}

bool query (int u, int l, int r, int k) {
    if (tr[u].l >= l && tr[u].r <= r) {
        for (auto mm: tr[u].mp) {
            if (mm.second % k) {
                return false;
            }
        }
        return true;
    }
    bool flg = 1;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)   flg &= query(u << 1, l, r, k);
    if (mid < r)    flg &= query(u << 1 | 1, l, r, k);
    return flg;
}

int main () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (k--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            modify(1, l, r, a[l]);
            a[l] = r;
        } else {
            int m;
            cin >> m;
            if (query(1, l, r, m)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}