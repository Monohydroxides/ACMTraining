#include <bits/stdc++.h>
using namespace std;

const int N = 65536 * 2 + 10;

int ans[N];
struct node {
    int l, r;
    int ctag, rtag;
} tr[N << 2];

void pushdown (int u) {
    if (tr[u].ctag != -1) {
        tr[u << 1].ctag = tr[u << 1 | 1].ctag = tr[u].ctag;
        tr[u << 1].rtag = tr[u << 1 | 1].rtag = 0;
        tr[u].ctag = -1;
    }
    if (tr[u].rtag) {
        tr[u << 1].rtag ^= 1;
        tr[u << 1 | 1].rtag ^= 1;
        tr[u].rtag = 0;
    }
}

void build (int u, int l, int r) {
    tr[u] = {l, r, -1, 0};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void cover (int u, int l, int r, int k) {
    if (l > r) return; // Test data have faults, spj
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].ctag = k;
        tr[u].rtag = 0;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= l) cover(u << 1, l, r, k);
    if (mid < r)  cover(u << 1 | 1, l, r, k);
}

void reverse (int u, int l, int r) {
    if (l > r) return; // Test data have faults, spj
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].rtag ^= 1;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= l) reverse(u << 1, l, r);
    if (mid < r)  reverse(u << 1 | 1, l, r);
}

void work (int u) {
    if (tr[u].l == tr[u].r) {
        if (tr[u].ctag == -1)
            ans[tr[u].l] = 0;
        else
            ans[tr[u].l] = tr[u].rtag ^ tr[u].ctag;
        return;
    }
    pushdown(u);
    work(u << 1);
    work(u << 1 | 1);
} 

int main () {
    int n = 65535 * 2;
    string op, setstr;
    build(1, 0, n);
    while (cin >> op >> setstr) {
        int p = 0;
        while (p < setstr.size() && setstr[p] != ',') p++;
        int l = 2 * stoi(setstr.substr(1, p - 1)) + (setstr[0] == '(');
        int r = 2 * stoi(setstr.substr(p + 1)) - (setstr[setstr.size() - 1] == ')');
        if (op == "U") {
            cover(1, l, r, 1);
        } else if (op == "I") {
            cover(1, 0, l - 1, 0);
            cover(1, r + 1, n, 0);
        } else if (op == "D") {
            cover(1, l, r, 0);
        } else if (op == "C") {
            reverse(1, 0, n);
            cover(1, 0, l - 1, 0);
            cover(1, r + 1, n, 0);
        } else if (op == "S") {
            reverse(1, l, r);
        }
    }
    work(1);
    int empty = 1;
    for (int i = 0; i <= n; i++) {
        if (ans[i]) {
            empty = 0;
            int j = i;
            while (j <= n && ans[j]) {
                j++;
            }
            cout << ((i & 1) ? '(' : '[') << i / 2 << "," << j / 2 << ((j & 1) ? ']' : ')') << ' ';
            i = j;
        }
    }
    if (empty) {
        cout << "empty set\n";
    }
    return 0;
}
