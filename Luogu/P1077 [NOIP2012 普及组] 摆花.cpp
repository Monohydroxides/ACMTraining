#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int mod = 1e6+7;
int n, m;
int a[N];
int f[2][N];

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;++i)	cin >> a[i];
	f[1][0]=1;
	int t=1;
	for(int i=1;i<=n;++i){
		t^=1;
		for(int j=0;j<=m;++j){
			f[t][j]=0;
			for(int k=0;k<=min(a[i],j);++k){
				f[t][j]=(f[t][j]+f[t^1][j-k])%mod;
			}
		}
	}
	cout << f[t][m] << endl;
	return 0;
}