#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[10010];
int w[3] = {7, 31, 365};

void init(){
	for(int i = 0; i <= 2; ++i){
		for(int j = w[i]; j <= 10000; ++j){
			for(int k = 1; k * w[i] <= j; ++k){
				dp[j] = min(dp[j], dp[j - k * w[i]] + k);
			}
		}
	}
}

void work(){
	ll n;
	cin >> n;
	ll res = n / 365;
	n %= 365;
	while(dp[n] == 0x3f3f3f3f && res >= 0){
		n += 365;
		res--;
	}
	if(res < 0){
		cout << -1 << endl;
	}else{
		cout << dp[n] + res << endl;
	}
	return;
}

int main(){
	int T;
	cin >> T;

	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	init();

	// for(int i = 1; i <= 500; ++i)	cout << i << " " << dp[i] << endl;
	while(T--)	work();
	return 0;
}