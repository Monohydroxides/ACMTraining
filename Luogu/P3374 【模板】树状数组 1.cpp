#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define all(a) ((a).begin(),(a).end())
#define debug(a) cout << "Debug: " << #a << ": " << a << "\n"
#define per(i,a,b,c) for(int i=a;i<b;i+=c)
#define pere(i,a,b,c) for(int i=a;i<=b;i+=c)
#define rep(i,a,b,c) for(int i=a;i>b;i-=c)
#define repe(i,a,b,c) for(int i=a;i>=b;i-=c)
#define mst(a,x) memset(a,x,sizeof a)

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 998244353;

const int N=100010;

int T;
int n,m;

namespace BIT{
	const int N=500010;
	int f[N];
	int lowbit(int x){return x&(-x);}
	void add(int x, int k){
		for(;x<=n;x+=lowbit(x)){
			f[x]+=k;
		}
	}
	int query(int x){
		int sum=0;
		for(;x;x-=lowbit(x)){
			sum+=f[x];
		}
		return sum;
	}
}

void work(){
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		int x;
		cin >> x;
		BIT::add(i,x);
	}
	for(int i=1;i<=m;++i){
		int op, x, y;
		cin >> op >> x >> y;
		if(op==2)	cout << BIT::query(y)-BIT::query(x-1) << endl;
		else{
			BIT::add(x,y);
		}
	}
}

int main(){
	cin.tie(0);
	// cin >> T;
	T=1;
	while(T--)	work();
	return 0;
}