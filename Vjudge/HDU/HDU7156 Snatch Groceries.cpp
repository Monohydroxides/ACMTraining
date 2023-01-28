#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void work(){
	int n;
	cin >> n;
	pair<int, int> seq[100010];
	for(int i = 1; i <= n; ++i){
		cin >> seq[i].first >> seq[i].second;
	}
	sort(seq + 1, seq + 1 + n);
	int res = 0;
	for(int i = 1; i <= n; ++i){
		if(i == n || seq[i + 1].first > seq[i].second){
			++res;
		}else{
			break;
		}
	}
	cout << res << endl;
	return;
}

int main(){
	int T;
	cin >> T;
	while(T--)	work();
	return 0;
}