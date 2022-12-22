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

long long calc(int x){
	LL a, b, c;
	a=x/3,b=x/3,c=x/3;
	int res=x%3;
	if(res==1)	a++;
	else if(res==2)	a++,b++;
	return 2*(a*b+a*c+b*c);
}

void work(){
	int n;
	cin >> n;
	int l=0, r=1e9;
	while(l<r){
		int mid=l+r>>1;
		if(calc(mid)>=n)	r=mid;
		else				l=mid+1;
	}
	cout << l << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}