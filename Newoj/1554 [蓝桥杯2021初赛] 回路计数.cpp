#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b? gcd(b, a % b) : a;
}

int a[25][25];
long long dp[1 << 21][21];

int main() {
	// memset(a, 0x3f, sizeof a);
	// for(int i = 1; i <= 21; i++)
	// 	for(int j = 1; j <= 21; j++)
	// 		if(gcd(i, j) == 1)
	// 			a[i - 1][j - 1] = a[j - 1][i - 1] = 1;
	// dp[1][0] = 1ll;
	// for(int i = 0; i < (1 << 21); i++)
	// 	for(int j = 0; j < 21; j++)
	// 		if((i >> j) & 1)
	// 			for(int k = 0; k < 21; k++)
	// 				if(((i ^ (1 << j)) >> k) & 1)
	// 					if(a[k][j] != 0x3f3f3f3f) 
    //                         dp[i][j] += dp[i ^ (1 << j)][k];
	// long long ans = 0;
	// for(int i = 1; i < 21; i++) {
	//     ans += dp[(1 << 21) - 1][i];
	// }
	// cout << ans;
    cout << "881012367360" << '\n';
	return 0;
}