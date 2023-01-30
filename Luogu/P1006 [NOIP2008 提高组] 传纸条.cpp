#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, m;
int a[N][N];
int f[2*N][N][N];


int main(){
	cin >> n >> m;
	for(int i=1;i<=n;++i)	for(int j=1;j<=m;++j)	cin >> a[i][j];
	f[2][1][1]=a[1][1];
	for(int k=2;k<=n+m;k++){
		for(int i1=1;i1<=n;++i1){
			for(int i2=1;i2<=n;++i2){
				int j1=k-i1, j2=k-i2;
				if(j1<1 || j2<1 || j1>m || j2>m)	continue;
				int w=a[i1][j1];
				if(i1!=i2)	w+=a[i2][j2];
				f[k][i1][i2]=max(f[k][i1][i2], f[k-1][i1-1][i2]+w);
				f[k][i1][i2]=max(f[k][i1][i2], f[k-1][i1][i2-1]+w);
				f[k][i1][i2]=max(f[k][i1][i2], f[k-1][i1-1][i2-1]+w);
				f[k][i1][i2]=max(f[k][i1][i2], f[k-1][i1][i2]+w);
			}
		}
	}
	cout << f[n+m][n][n] << endl;
	return 0;
}