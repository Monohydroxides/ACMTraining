#include <bits/stdc++.h>
using namespace std;

int T;

void work(){
	int n, x, maxcnt=0;
	cin >> n;
	unordered_map<int, int> mp;
	for(int i=1;i<=n;++i){
		cin >> x;
		mp[x]++;
		if(maxcnt<mp[x])	maxcnt=mp[x];
	}
	int res=0;
	while(maxcnt<n){
		res++;
		res+=min(maxcnt, n-maxcnt);
		maxcnt*=2;
	}
	cout << res << endl;
}

int main(){
	cin >> T;
	while(T--)	work();
	return 0;
}