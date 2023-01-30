#include <bits/stdc++.h>
using namespace std;

const int N = 310;

int n, m, k;
int h[N], e[2 * N], ne[2 * N], w[2 * N], idx;
int sz[N];
int dp[N][N][2], tmp[N][2];

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dfs(int u, int fa){
	sz[u] = 1;
	for(int i = h[u]; ~i; i = ne[i]){
		int v = e[i];
		if(v == fa)	continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
	dp[u][0][0] = dp[u][1][1] = 0;
	for(int i = h[u]; ~i; i = ne[i]){
		int v = e[i];
		if(v == fa)	continue;
		memcpy(tmp, dp[u], sizeof dp[u]);
		memset(dp[u], 0x3f, sizeof dp[u]);
		for(int j = 0; j <= min(sz[u], k); ++j){
			for(int p = 0; p <= j; ++p){
				dp[u][j][0] = min(dp[u][j][0], min(dp[v][p][0] + tmp[j - p][0] + (m == 2) * w[i], dp[v][p][1] + tmp[j - p][0]));
				dp[u][j][1] = min(dp[u][j][1], min(dp[v][p][0] + tmp[j - p][1], dp[v][p][1] + tmp[j - p][1] + w[i]));
			}
		}
	}
}

int main(){
	cin >> n >> m >> k;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= n - 1; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	if(k + m - 1 > n){
		cout << -1 << endl;
		return 0;
	}
	memset(dp, 0x3f, sizeof dp);
	dfs(1, -1);
	cout << dp[1][k][1] << endl;
	return 0;
}