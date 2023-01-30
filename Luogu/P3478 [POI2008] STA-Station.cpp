#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

int n;
int h[N], e[2 * N], ne[2 * N], idx;
int dep[N], sz[N];
ll dp[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int father, int depth) {
    sz[u] = 1, dep[u] = depth;
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(v == father) continue;
        dfs1(v, u, depth + 1);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int father) {
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(v == father)  continue;
        dp[v] = dp[u] + n - 2 * sz[v];
        dfs2(v, u);
    }
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs1(1, -1, 1);
    for(int i = 1; i <= n; ++i) {
        dp[1] += dep[i];
    }
    dfs2(1, -1);
    ll maxn = 0, res = -1;
    for(int i = 1; i <= n; ++i) {
        // cout << sz[i] << endl;
        if(maxn < dp[i]) {
            maxn = dp[i];
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}