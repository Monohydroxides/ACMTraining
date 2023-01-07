#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

int n, facsum[N];
int h[N], e[N], ne[N], idx;
int d1[N], d2[N], res;

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs (int u) {
    if (d1[u]) return;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);
        if (d1[j] + 1 >= d1[u]) d2[u] = d1[u], d1[u] = d1[j] + 1;
        else if (d1[j] + 1 > d2[u]) d2[u] = d1[j] + 1;
    }
    res = max(res, d1[u] + d2[u]);
}
int main () {
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= n / i; j ++ )
            facsum[i * j] += i;
    for (int i = 2; i <= n; i++)
        if (facsum[i] < i)
            add(facsum[i], i);
    for (int i = 1; i <= n; i++) dfs(i);
    cout << res << '\n';
    return 0;
}
