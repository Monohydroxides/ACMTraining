#include <bits/stdc++.h>
using namespace std;

const int N = 1510, M = 200010;

int n;
int h[N], e[M], ne[M], eid;
int ind[N];

int dp[N][2];

void add (int a, int b) {
    e[eid] = b, ne[eid] = h[a], h[a] = eid++;
}

void dfs (int u) {
    dp[u][1] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        dfs(v);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][1], dp[v][0]);
    }
}

int main () {
    while (~scanf("%d", &n)) {
        memset(h, -1, sizeof h);
        memset(ind, 0, sizeof ind);
        memset(dp, 0, sizeof dp);
        eid = 0;
        for (int i = 0; i < n; i ++ ) {
            int a, b, siz;
            scanf("%d:(%d) ", &a, &siz);
            a++;
            while (siz--) {
                scanf("%d", &b);
                b++;
                add(a, b);
                ind[b]++;
            }
        }
        int root = 1;
        while (ind[root]) root++;
        dfs(root);
        printf("%d\n", min(dp[root][0], dp[root][1]));
    }
    return 0;
}