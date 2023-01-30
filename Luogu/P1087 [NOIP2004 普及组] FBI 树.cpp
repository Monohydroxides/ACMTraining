#include <bits/stdc++.h>
using namespace std;

const int N=1<<10+10;

int n,m;
int a[1<<10+10];
struct node{
	int l, r;
	int st;
}tr[N*4];

void pushup(int u){
	if(tr[u<<1].st==2 || tr[u<<1|1].st==2){
		tr[u].st=2;
	}else if(tr[u<<1].st!=tr[u<<1|1].st){
		tr[u].st=2;
	}else{
		tr[u].st=tr[u<<1].st;
	}
}

void build(int u, int l, int r){
	if(l==r){
		tr[u]={l,r,a[l]};
	}else{
		tr[u]={l,r,-1};
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		pushup(u);
	}
}

char conv(int st){
	if(st==0)	return 'B';
	else if(st==1)	return 'I';
	else			return 'F';
}

void query(int u, int l, int r){
	if(u>m)	return;
	else{
		query(u<<1,l,r);
		query(u<<1|1,l,r);
		printf("%c",conv(tr[u].st));
	}
}

int main(){
	cin >> n;
	m=(1<<(n+1))-1;
	n=1<<n;
	for(int i=1;i<=n;++i)	scanf("%1d",&a[i]);
	build(1,1,n);
	query(1,1,n);
	return 0;
}