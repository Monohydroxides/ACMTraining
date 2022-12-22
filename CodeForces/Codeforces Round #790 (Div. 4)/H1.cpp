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

int T;
int n;
int a[1010];

void work(){
	cin >> n;
	for(int i=1;i<=n;++i)	cin >> a[i];
	long long res=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j){
			if(a[j]>=a[i])	res++;
		}
	}
	cout << res << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}