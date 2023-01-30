#include <bits/stdc++.h>
using namespace std;

const int N = 5010, M = 500010, mod = 80112002;

int n, m;
int h[N], e[M], ne[M], idx;
int f[N];
int outd[N], ind[N];

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        ind[b]++, outd[a]++;
    }
    queue<int> qu;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            f[i] = 1;
            qu.push(i);
        }
    }
    while (qu.size()) {
        int cur = qu.front();
        qu.pop();
        for (int i = h[cur]; i != -1; i = ne[i]) {
            int v = e[i];
            f[v] = (f[v] + f[cur]) % mod;
            ind[v]--;
            if (ind[v] == 0) {
                qu.push(v);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (outd[i] == 0) {
            res = (res + f[i]) % mod;
        }
    }
    cout << res << endl;
    return 0;
}