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
int a[55];
void work(){
	int n;
    cin >> n;
    int minn=INT_MAX;
    long long sum=0;
    for(int i=1;i<=n;++i)   cin >> a[i], minn=min(minn,a[i]);
    for(int i=1;i<=n;++i)   sum+=a[i]-minn;
    cout << sum << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}