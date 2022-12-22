#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2010;

int n, k;
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
int sz[N];
LL dp[N][N];

int read(){
    int num=0,k=1;
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

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dfs(int u, int fa){
	sz[u] = 1, dp[u][0] = dp[u][1] = 0;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(j == fa)	continue;
		dfs(j, u);
		sz[u] += sz[j];
		for(int a = min(sz[u], k); a >= 0; --a){
			for(int b = 0; b <= min(a, sz[j]); ++b){
				if(dp[u][a - b] == -1) continue;
				LL wt = (LL) (k - b) * b * w[i] + (LL) (n - k - sz[j] + b) * (sz[j] - b) * w[i];
				dp[u][a] = max(dp[u][a], dp[u][a - b] + dp[j][b] + wt);
			}
		}
	}
}

int main(){
	memset(h, -1, sizeof h);
	memset(dp, -1, sizeof dp);
	n = read(), k = read();
	for(int i = 1; i < n; ++i){
		int a, b, c;
		a = read(), b = read(), c = read();
		add(a, b, c);
		add(b, a, c);
	}
	dfs(1, -1);
	// for(int i = 1; i <= n; ++i)	cout << sz[i] << " ";
	cout << dp[1][k] << endl;
	return 0;
}