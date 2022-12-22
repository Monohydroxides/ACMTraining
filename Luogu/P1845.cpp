#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

typedef pair<int, int> PII;

int n;
int g[N][N], vis[N][N];
int d[4][2]={0,1,0,-1,1,0,-1,0};

int srh(int x, int y){
	int res=0;
	vis[x][y]=1;
	queue<pair<int, PII>> que;
	que.push({1, {x, y}});
	while(que.size()){
		auto t=que.front();
		res=max(res, t.first);
		que.pop();
		for(int i=0;i<4;++i){
			int nx=t.second.first+d[i][0], ny=t.second.second+d[i][1];
			if(nx<1 || nx>n || ny<1 || ny>n)	continue;
			if(!g[nx][ny] || vis[nx][ny])		continue;
			vis[nx][ny]=t.first+1;
			que.push({t.first+1, {nx, ny}}); 
		}
	}
	return res;
}

int main(){
	scanf("%d", &n);
	vector<int> ans;
	for(int i=1;i<=n;++i)	for(int j=1;j<=n;++j)	scanf("%1d", &g[i][j]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(g[i][j] && !vis[i][j]){
				ans.push_back(srh(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();++i){
		cout << ans[i] << endl;
	}
	return 0;
}