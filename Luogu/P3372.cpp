#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100010;

int n, m;
LL w[N];
struct node{
	int l, r;
	LL sum, add;
}tr[N * 4];

void pushup(int u){
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
	node &rot = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
	l.sum += rot.add * (l.r - l.l + 1), l.add += rot.add;
	r.sum += rot.add * (r.r - r.l + 1), r.add += rot.add;
	rot.add = 0; 
}

void build(int u, int l, int r){
	if(l == r){
		tr[u] = {l, r, w[l], 0};
	}else{
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}

void modify(int u, int l, int r, LL v){
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].sum += (tr[u].r - tr[u].l + 1) * v;
		tr[u].add += v;
	}else{
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(mid >= l)	modify(u << 1, l, r, v);
		if(mid < r)		modify(u << 1 | 1, l, r, v);
		pushup(u);	
	}
}

LL query(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].sum;
	}
	pushdown(u);
	LL sum = 0;
	int mid = tr[u].l + tr[u].r >> 1;
	if(mid >= l)	sum += query(u << 1, l, r);
	if(mid < r)		sum += query(u << 1 | 1, l, r);
	return sum;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)	scanf("%lld", &w[i]);
	build(1, 1, n);
	for(int i = 1; i <= m; ++i){
		int op, x, y; LL k;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1){
			scanf("%lld", &k);
			modify(1, x, y, k);
		}else{
			printf("%lld\n", query(1, x, y));
		}
	}
	return 0;
}