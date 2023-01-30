#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

char a[N], b[N];
int n, m;
int f[N][N];

int main(){
	cin >> a+1 >> b+1;
	n=strlen(a+1), m=strlen(b+1);
	for(int i=1;i<=n;++i)	f[i][0]=i;
	for(int j=1;j<=m;++j)	f[0][j]=j;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i]==b[j]){
				f[i][j]=f[i-1][j-1];
			}else{
				f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}