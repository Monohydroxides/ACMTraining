#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000010;

int n, s;
LL res = 0;
int h[N], e[N], ne[N], idx;
LL w[N];
LL maxn[N];

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dfs(int x, int fa){
	for(int i = h[x]; ~i; i = ne[i])	if(e[i] != fa)	dfs(e[i], x);
	for(int i = h[x]; ~i; i = ne[i])	if(e[i] != fa) 	maxn[x] = max(maxn[x], w[i]);
	for(int i = h[x]; ~i; i = ne[i])	if(e[i] != fa)	res += maxn[x] - w[i]; 
	if(fa != -1){
		for(int i = h[fa]; ~i; i = ne[i]){
			if(e[i] == x){
				w[i] += maxn[x];
			}
		}
	}
}

int main(){
	memset(h, -1, sizeof h);
	cin >> n >> s;
	for(int i = 1; i <= n - 1; ++i){
		int a, b, t;
		cin >> a >> b >> t;
		add(a, b, t);
		add(b, a, t);
	}
	dfs(s, -1);
	cout << res << endl;
	return 0;
}