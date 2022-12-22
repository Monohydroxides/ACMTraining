#include<bits/stdc++.h>

using namespace std;

int ans[100001];

int main() {
	int mod = 100003;
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= k;i++){
		ans[i] = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(i - j >= 1){
				ans[i] += ans[i-j];
				ans[i] %= mod;
			}	
		}
	}
	printf("%d",ans[n] % mod);
	return 0;
}