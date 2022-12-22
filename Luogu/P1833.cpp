#include <bits/stdc++.h>
using namespace std;

// const int N = 10010;
// 
// int sth, edh, stm, edm;
// int n, T;
// int t[N], c[N], p[N];
// int f[2][1010];

// int main(){
	// scanf("%d:%d %d:%d %d", &sth, &stm, &edh, &edm, &n);
	// T = (edh-sth-1)*60+(60-stm+edm);
	// for(int i=1;i<=n;++i){
		// int aa, bb, cc;
		// cin >> aa >> bb >> cc;
		// t[i]=aa, c[i]=bb, p[i]=cc;
	// }
	// int rol=1;
	// for(int i=1;i<=n;++i){
		// rol^=1;
		// for(int j=1;j<=T;++j){
			// for(int k=0;((p[i]!=0 && k<=p[i]) || (p[i]==0))&&(k*t[i]<=j);++k){
				// f[rol][j]=max(f[rol][j], f[rol^1][j-k*t[i]] + c[i]*k);
			// }
		// }
	// }
	// cout << f[rol][T] << endl;
    // return 0;
// }

const int N = 200010;

int sth, edh, stm, edm;
int n, T;
int t[N], c[N], p[N], cnt;
int f[1010];

int main(){
	scanf("%d:%d %d:%d %d", &sth, &stm, &edh, &edm, &n);
	T = (edh-sth-1)*60+(60-stm+edm);
	for(int i=1;i<=n;++i){
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		if(cc==0)	cc=1023;
		int k=1;
		while(k<=cc){
			t[++cnt]=aa*k, c[cnt]=bb*k;
			cc-=k;
			k*=2;
		}
		if(cc>=1){
			t[++cnt]=aa*cc, c[cnt]=bb*cc;
		}
	}
	for(int i=1;i<=cnt;++i){
		for(int j=T;j>=t[i];--j){
			f[j]=max(f[j], f[j-t[i]] + c[i]);
		}
	}
	cout << f[T] << endl;
    return 0;
}