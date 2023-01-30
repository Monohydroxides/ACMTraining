#include <bits/stdc++.h>
using namespace std;

const int N=1510;

int n, res;
int dp[N][N];
int h[N], e[N * 2], ne[N * 2], idx;

void add(int a, int b){
	e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

void dfs(int u, int father){
    dp[u][1] = 1, dp[u][0] = 0;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(j == father)	continue;
		dfs(j, u);
		dp[u][0] += dp[j][1];
		dp[u][1] += min(dp[j][0], dp[j][1]);
	}
}

int main(){
	memset(h,-1,sizeof h);
	cin >> n;
	for(int i=1;i<=n;++i){
		int a, k, b;
		cin >> a >> k;
		for(int j=1;j<=k;++j){
			cin >> b;
			add(a, b), add(b, a);
		}
	}
	dfs(0, -1);
	cout << min(dp[0][1], dp[0][0]) << endl;
	return 0;
}