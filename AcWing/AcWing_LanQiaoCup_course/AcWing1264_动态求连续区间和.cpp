#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;

int tr[N];

int lowbit (int x) { return x & (-x); }

void add (int x, int k) {
    for (; x <= n; x += lowbit(x)) tr[x] += k;
}

int query (int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += tr[x];
    return res;
}


int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(i, x);
    }
    while (m--) {
        int k, a, b;
        cin >> k >> a >> b;
        if (!k) {
            cout << query(b) - query(a - 1) << '\n';
        } else {
            add(a, b);
        }
    }
    return 0;
}