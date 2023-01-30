#include <bits/stdc++.h>
using namespace std;

const int N = 610;

int n, m;
int h[N], e[N], ne[N], idx, w[N];
int f[N][N];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int cnt){
	if(cnt <= 0)	return;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		for(int k = 0; k < cnt; ++k){
			f[j][k] = f[u][k] + w[j];
		}
		dfs(j, cnt - 1);
		for(int k = 1; k <= cnt; ++k){
			f[u][k] = max(f[u][k], f[j][k - 1]);
		}
	}
}

int main(){
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		int k, s;
		cin >> k >> s;
		add(k, i);
		w[i] = s;
	}
	dfs(0, m);
	cout << f[0][m] << endl;
	return 0;
}