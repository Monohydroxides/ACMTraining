#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, x, y;
	cin >> t;
	while(t--){
		cin >> x >> y;
		int ex[100010];
		memset(ex, 0, sizeof(ex));
		queue<pair<int, int> >q;
		q.push({y, 0});
		ex[y] = 1;
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			if(now.first == x){printf("%d\n",now.second); break;}
			if(!(now.first % 2) && !ex[now.first / 2])	ex[now.first / 2] = 1, q.push({now.first / 2, now.second + 1});
			if(now.first - 1 > 0 && !ex[now.first - 1])	ex[now.first - 1] = 1, q.push({now.first - 1, now.second + 1});
			if(now.first + 1 < 100001 && !ex[now.first + 1])	ex[now.first + 1] = 1, q.push({now.first + 1, now.second + 1});
		}
	}
	return 0;
}