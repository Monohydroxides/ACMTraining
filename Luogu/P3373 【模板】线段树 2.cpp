#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1e5+10;

int n, m, p;
int w[N];

struct node{
	int l, r;
	int sum, add, mul;
}tr[N*4];

void eval(int u, int ad, int mu){
	tr[u].sum=((LL)tr[u].sum*mu+(LL)(tr[u].r-tr[u].l+1)*ad)%p;
	tr[u].add=((LL)tr[u].add*mu+ad)%p;
	tr[u].mul=((LL)tr[u].mul*mu)%p;
}

void pushup(int u){
	tr[u].sum=((LL)tr[u<<1].sum+tr[u<<1|1].sum) % p;
}

void pushdown(int u){
	eval(u<<1, tr[u].add, tr[u].mul);
	eval(u<<1|1, tr[u].add, tr[u].mul);
	tr[u].add=0, tr[u].mul=1;
}

void build(int u, int l, int r){
	if(l==r){
		tr[u]={l,r,w[r],0,1};
	}else{
		tr[u]={l,r,0,0,1};
		int mid=l+r>>1;
		build(u<<1, l, mid);
		build(u<<1|1, mid+1, r);
		pushup(u);
	}
}

void modify(int u, int l, int r, int ad, int mu){
	if(tr[u].l >= l && tr[u].r <= r){
		eval(u, ad, mu);
	}else{
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid)	modify(u<<1,l,r,ad,mu);
		if(r>mid)	modify(u<<1|1,l,r,ad,mu);
		pushup(u);
	}
}

int query(int u, int l, int r){
	if(tr[u].l>=l && tr[u].r<=r)	return tr[u].sum;
	pushdown(u);
	int res=0;
	int mid=tr[u].l+tr[u].r>>1;
	if(l<=mid)	res=((LL)res+query(u<<1,l,r))%p;
	if(r>mid)	res=((LL)res+query(u<<1|1,l,r))%p;
	return res;
}

int main(){
	cin >> n >> m >> p;
	for(int i=1;i<=n;++i)	cin >> w[i];
	build(1,1,n);
	for(int i=1;i<=m;++i){
		int op, x, y, k;
		cin >> op >> x >> y;
		if(op==1){
			cin >> k;
			modify(1,x,y,0,k);
		}else if(op==2){
			cin >> k;
			modify(1,x,y,k,1);
		}else{
			cout << query(1,x,y) << endl;
		}
	}
	return 0;
}