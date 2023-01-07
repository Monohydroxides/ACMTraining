#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int n, ans;
int h[N], e[M], ne[M], wi[M], eid;

void add (int a, int b, int c) {
    e[eid] = b, ne[eid] = h[a], wi[eid] = c, h[a] = eid++;
}

int dfs (int u, int father) {
    int d1 = 0, d2 = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == father) continue;
        int ans = dfs(v, u);
        if (ans + wi[i] >= d1) {
            d2 = d1, d1 = ans + wi[i];
        } else if (ans + wi[i] >= d2) {
            d2 = ans + wi[i];
        }
    }
    ans = max(ans, d1 + d2);
    return d1;
}

int main () {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1);
    cout << ans << '\n';
    return 0;
}