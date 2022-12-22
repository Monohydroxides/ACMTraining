#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define all(a) ((a).begin(),(a).end())
#define debug(a) cout << "Debug: " << #a << ": " << a << "\n"
#define per(i,a,b,c) for(int i=a;i<b;i+=c)
#define pere(i,a,b,c) for(int i=a;i<=b;i+=c)
#define rep(i,a,b,c) for(int i=a;i>b;i-=c)
#define repe(i,a,b,c) for(int i=a;i>=b;i-=c)
#define mst(a,x) memset(a,x,sizeof a)

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 998244353;

const int n = 1000010;

int T;
int n;

int h[N], e[N], ne[N], idx;
int dep[N], sz[N], fa[N], son[N];
int id[N], nw[N], top[N], cnt;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a]++, w[idx] = c, h[a] = idx++;
}

void dfs1(int u, int father, int depth){
    fa[u]=father, sz[u]=1, dep[u]=depth;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==father)   continue;
        dfs1(j,u,depth+1);
        sz[u]+=sz[j];
        if(sz[son[u]]<sz[j])    son[u]=j;
    }
}

void dfs2(int u, int father){
    id[u]=++cnt, nw[cnt]=w[u], top[u]=father;
    if(!son[u]) return;
    dfs2(son[u], father);
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa[u] || j==son[u])   continue;
        dfs2(j, j);
    }
}


void work(){
	cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; ++i){
        int u, v, x;
        cin >> u >> v >> x;
        add(u, v, x), add(v, u, x);
    }
    dfs1(1, -1, 1);
    dfs2(1, 1);
	return;
}

int main(){
	cin.tie(0);
	T = 1;
	while(T--)	work();
	return 0;
}