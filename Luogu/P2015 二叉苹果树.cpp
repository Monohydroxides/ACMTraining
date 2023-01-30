#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 210;

int res = 0;
int n, q;
int h[N], e[N], ne[N], w[N], idx;
int sz[N];
LL f[N][N];

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dfs(int u, int fa){
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(j == fa)	continue;
		dfs(j, u);
		sz[u] += sz[j] + 1;
		for(int p = min(sz[u], q); p >= 0; --p){
			for(int k = min(sz[j], p - 1); k >= 0; --k){
				f[u][p] = max(f[u][p], f[u][p - k - 1] + f[j][k] + w[i]);
			}
		}
	}
}

int main(){
	memset(h, -1, sizeof h);
	cin >> n >> q;
	for(int i = 1; i <= n - 1; ++i){
		int a, b, t;
		cin >> a >> b >> t;
		add(a, b, t);
		add(b, a, t);
	}
	dfs(1, -1);
	cout << f[1][q] << endl;
	return 0;
}