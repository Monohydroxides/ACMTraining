#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
string str;

struct node {
    int l, r;
    int val;
    char mapp[26];
} tr[N << 7];
int vid;

void pushdown (int u) {
    for (int i = 0; i < 26; i++) {
        tr[tr[u].l].mapp[i] = tr[u].mapp[tr[tr[u].l].mapp[i]];
        tr[tr[u].r].mapp[i] = tr[u].mapp[tr[tr[u].r].mapp[i]];
    }
    for (int i = 0; i < 26; i++) {
        tr[u].mapp[i] = i;
    }
}

int build (int l, int r) {
    int u = ++vid;
    for (int i = 0; i < 26; i++) {
        tr[u].mapp[i] = i;
    }
    if (l == r) {
        tr[u].val = str[l] - 'a';
        return u;
    }
    int mid = l + r >> 1;
    tr[u].l = build(l, mid);
    tr[u].r = build(mid + 1, r);
    return u;
}

void modify (int p, int trl, int trr, int l, int r, int s, int t) {
    if (trl >= l && trr <= r) {
        for (int i = 0; i < 26; i++) {
            if (tr[p].mapp[i] == s - 'a') {
                tr[p].mapp[i] = t - 'a';
            }
        }
        return;
    }
    pushdown(p);
    int mid = trl + trr >> 1;
    if (mid >= l) modify(tr[p].l, trl, mid, l, r, s, t);
    if (mid < r)  modify(tr[p].r, mid + 1, trr, l, r, s, t);
}

void query (int u, int l, int r) {
    if (l == r) {
        cout << (char) (tr[u].mapp[tr[u].val] + 'a');
        return;
    }
    pushdown(u);
    int mid = l + r >> 1;
    query(tr[u].l, l, mid);
    query(tr[u].r, mid + 1, r);
}

int main () {
    cin >> str;
    n = str.size();
    str = " " + str;
    build(1, n);
    int opt;
    cin >> opt;
    while (opt--) {
        int l, r;
        char s, t;
        cin >> l >> r >> s >> t;
        modify(1, 1, n, l, r, s, t);
        // query(1, 1, n);
        // cout << '\n';
    }
    query(1, 1, n);
    return 0;
}
