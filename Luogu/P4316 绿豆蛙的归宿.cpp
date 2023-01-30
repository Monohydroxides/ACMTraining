#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], out[N], w[N], idx;
double f[N];

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

double dfs(int u){
	if(f[u] >= 0)	return f[u];
	f[u] = 0.0;	
	for(int i = h[u]; ~i; i = ne[i]){
		int v = e[i];
		f[u] += (w[i] + dfs(v)) / out[u];
	}
	return f[u];
}

int main(){
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		out[a]++;
	}
	for(int i = 1; i <= n; ++i)	f[i] = -1;
	dfs(1);
	// for(int i = 1; i <= n; ++i)	cout << f[i] << " ";
	printf("%.2lf\n", f[1]);
	return 0;	
}