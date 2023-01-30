#include <bits/stdc++.h>
using namespace std;

const int N=5010, M=2e5+10;

struct edge{
	int st, ed;
	int w;
	bool operator< (const struct edge& e)const{
		return w<e.w;
	}
}edges[M];

int n, m;
int fa[N];

int find(int x){
	if(x==fa[x])	return x;
	return fa[x]=find(fa[x]);
}

void init(){
	for(int i=1;i<=n;++i)	fa[i]=i;
	sort(edges+1,edges+1+m);
}

int kru(){
	int cnt=0, t=0;
	for(int i=1;i<=m;++i){
		int pa=find(edges[i].st), pb=find(edges[i].ed);
		if(pa!=pb){
			cnt++;
			t+=edges[i].w;
			fa[pa]=pb;
		}
		if(cnt==n-1)break;
	}
	if(cnt==n-1)	return t;
	else			return 0x3f3f3f3f;
}

int main(){
	cin >> n >> m;
	int x, y, z;
	for(int i=1;i<=m;++i){
		cin >> x >> y >> z;
		edges[i]={x,y,z};
	}
	init();
	int t=kru();
	if(t==0x3f3f3f3f)	printf("orz\n");
	else				printf("%d\n", t);
	return 0;
}