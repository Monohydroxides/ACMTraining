#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;

long long tr[N];

int lowbit (int x) {
    return x & (-x);
}

void add (int x, int k) {
    for (; x <= n; x += lowbit(x)) {
        tr[x] += k;
    }
} 

long long query (int x) {
    long long res = 0;
    for (; x; x -= lowbit(x)) {
        res += tr[x];
    }
    return res;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        string op;
        int x, y;
        cin >> op >> x >> y;
        if (op == "x") {
            add(x, y);
        } else {
            cout << query(y) - query(x - 1) << '\n';
        }
    }
    return 0;
}