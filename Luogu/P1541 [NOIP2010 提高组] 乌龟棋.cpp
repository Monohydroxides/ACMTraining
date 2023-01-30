#include <bits/stdc++.h>
using namespace std;

const int N = 45;

int n, m;
int a[360],cnt[5];
int f[N][N][N][N];

int calc(int e, int b, int c, int d){
	return a[cnt[1]-e+2*(cnt[2]-b)+3*(cnt[3]-c)+4*(cnt[4]-d)+1];
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;++i)	cin >> a[i];
	for(int i=1;i<=m;++i){
		int x;
		cin >> x;
		cnt[x]++;
	}
	f[0][0][0][0]=a[1];
	for(int i=0;i<=cnt[1];++i){
		for(int j=0;j<=cnt[2];++j){
			for(int k=0;k<=cnt[3];++k){
				for(int p=0;p<=cnt[4];++p){
					if(i>=1)	f[i][j][k][p]=max(f[i][j][k][p], f[i-1][j][k][p]+calc(i-1,j,k,p));
					if(j>=1)	f[i][j][k][p]=max(f[i][j][k][p], f[i][j-1][k][p]+calc(i,j-1,k,p));
					if(k>=1)	f[i][j][k][p]=max(f[i][j][k][p], f[i][j][k-1][p]+calc(i,j,k-1,p));
					if(p>=1)	f[i][j][k][p]=max(f[i][j][k][p], f[i][j][k][p-1]+calc(i,j,k,p-1));
				}
			}
		}
	}
	cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
	return 0;
}