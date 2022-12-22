#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int n, m;

int a[N];
struct node{
	int l, r;
	int cnt;
}tr[N*25];
int rot[N], idx;
vector<int> dsc;

int find(int x){
	return lower_bound(dsc.begin(),dsc.end(),x)-dsc.begin();
}

int build(int l, int r){
	int p=++idx;
	if(l==r)	return p;
	int mid=l+r>>1;
	tr[p].l=build(l,mid),tr[p].r=build(mid+1,r);
	return p;
}

int insert(int p, int l, int r, int x){
	int q=++idx;
	tr[q]=tr[p];
	if(l==r){
		tr[q].cnt++;
		return q;
	}
	int mid=l+r>>1;
	if(x<=mid)	tr[q].l=insert(tr[p].l,l,mid,x);
	else		tr[q].r=insert(tr[p].r,mid+1,r,x);
	tr[q].cnt=tr[tr[q].l].cnt+tr[tr[q].r].cnt;
	return q;
}

int query(int p, int q, int l, int r, int k){
	if(l==r)	return r;
	int mid=l+r>>1;
	int cnt=tr[tr[q].l].cnt-tr[tr[p].l].cnt;
	if(cnt>=k)	return query(tr[p].l, tr[q].l, l, mid, k);
	else		return query(tr[p].r, tr[q].r, mid+1, r, k-cnt);	
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;++i)	cin >> a[i], dsc.push_back(a[i]);
	sort(dsc.begin(),dsc.end());
	dsc.erase(unique(dsc.begin(),dsc.end()),dsc.end());
	
	rot[0]=build(0,dsc.size()-1);
	
	for(int i=1;i<=n;++i)	rot[i]=insert(rot[i-1],0,dsc.size()-1,find(a[i]));
	while(m--){
		int x, y, k;
		cin >> x >> y >> k;
		cout << dsc[query(rot[x-1],rot[y],0,dsc.size()-1,k)] << endl;
	}
	return 0;
}