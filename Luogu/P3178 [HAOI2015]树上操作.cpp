#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100010;

typedef long long LL;

int n, m;
int w[N];

int h[N], e[2 * N], ne[2 * N], idx;

int fa[N], dep[N], sz[N];
int id[N], nw[N], top[N], son[N], cnt;

struct node{
	int l, r;
	LL add, sum;
}tr[N * 4];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int father, int depth){
	fa[u] = father, dep[u] = depth, sz[u] = 1;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(j == father)	continue;
		dfs1(j, u, depth + 1);
		sz[u] += sz[j];
		if(sz[son[u]] < sz[j])	son[u] = j;
	}
}

void dfs2(int u, int tp){
	id[u] = ++cnt, nw[cnt] = w[u], top[u] = tp;
	if(!son[u])	return;
	dfs2(son[u], tp);
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(j == fa[u] || j == son[u])	continue;
		dfs2(j, j);
	}
}

void pushup(int u){
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
	tr[u << 1].sum += tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
	tr[u << 1 | 1].sum += tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
	tr[u << 1].add += tr[u].add;
	tr[u << 1 | 1].add += tr[u].add;
	tr[u].add = 0;
}

void build(int u, int l, int r){
	if(l == r){
		tr[u] = {l, r, 0, nw[r]};
		return;
	}
	tr[u] = {l, r};
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, int k){
	if(l <= tr[u].l && tr[u].r <= r){
		tr[u].sum += k * (tr[u].r - tr[u].l + 1);
		tr[u].add += k;
		return;
	}
	pushdown(u);
	int mid = tr[u].r + tr[u].l >> 1;
	if(l <= mid)	update(u << 1, l, r, k);
	if(mid < r)		update(u << 1 | 1, l, r, k); 
	pushup(u);
}

LL query(int u, int l, int r){
	if(l <= tr[u].l && tr[u].r <= r){
		return tr[u].sum;
	}
	pushdown(u);
	LL res = 0;
	int mid = tr[u].r + tr[u].l >> 1;
	if(l <= mid)	res += query(u << 1, l, r);
	if(mid < r)		res += query(u << 1 | 1, l, r);
	return res;
}

void update_path(int x, int a){
	update(1, id[x], id[x] + sz[x] - 1, a);
}

LL query_path(int x){
	LL res = 0;
	while(top[x] != top[1]){
		res += query(1, id[top[x]], id[x]);
		x = fa[top[x]];
	}
	res += query(1, id[1], id[x]);
	return res;
}

signed main(){
	cin.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= n; ++i){
		cin >> w[i];
	}
	for(int i = 2; i <= n; ++i){
		int x, y;
		cin >> x >> y;
		add(x, y), add(y, x);		
	}
	dfs1(1, -1, 1);
	dfs2(1, 1);
	build(1, 1, n);
	for(int i = 1; i <= m; ++i){
		int op, x, a;
		cin >> op;
		if(op == 1){
			cin >> x >> a;
			update(1, id[x], id[x], a);
		}else if(op == 2){
			cin >> x >> a;
			update_path(x, a);
		}else{
			cin >> x;
			cout << query_path(x) << endl;
		}
	}
	return 0;
}