#include <bits/stdc++.h>
using namespace std;
const int N = 110;

int n, m;
int h[N], e[N], ne[N], w[N], cst[N], idx;
int dp[N][40000];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int read(){
	int num = 0, k = 1;
	char c=getchar();
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	if(c=='-'){
		k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=(num<<3)+(num<<1)+(c^48);
		c=getchar();
	}
	return num*k;
}

void dfs(int u, int fa, int cur){
	if(cur <= 0)	return;
	for(int i = h[u]; ~i; i = ne[i]){
		int v = e[i];
		if(v == fa)	continue;
		for(int j = n - cst[v]; j >= 0; --j){
			dp[v][j] = dp[u][j] + w[v];
		}
		dfs(v, u, cur - cst[u]);
		for(int j = n; j >= cst[v]; --j){
			dp[u][j] = max(dp[u][j], dp[v][j - cst[v]]);
		}
	}
}

int main(){
	memset(h, -1, sizeof h);
	n = read(), m = read();
	for(int i = 1; i <= m; ++i){
		int a, b, c;
		a = read(), b = read(), c = read();
		cst[i] = a;
		w[i] = a * b;
		add(c, i), add(i, c);
	}
	dfs(0, -1, n);
	cout << dp[0][n] << endl;
	return 0;
}