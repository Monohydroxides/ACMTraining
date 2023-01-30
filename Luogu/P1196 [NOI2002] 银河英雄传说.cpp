#include <bits/stdc++.h>
using namespace std;

int T;
int fa[30010], dst[30010], sz[30010];

int find(int x){
	if(fa[x]==x)	return x;
	int rt=find(fa[x]);
	dst[x]+=dst[fa[x]];
	return fa[x]=rt;
}

int main(){
	cin >> T;
	for(int i=1;i<=30000;++i)	fa[i]=i, dst[i]=0, sz[i]=1;
	while(T--){
		char op; int i, j;
		cin >> op >> i >> j;
		if(op=='M'){
			int pi=find(i), pj=find(j);
			fa[pi]=pj;
			dst[pi]+=sz[pj];
			sz[pj]+=sz[pi];
		}else{
			int pi=find(i), pj=find(j);
			if(pi!=pj){
				cout << -1 << endl;
			}else{
				cout << abs(dst[i]-dst[j]) - 1 << endl;
			}
		}
	}
	return 0;
}