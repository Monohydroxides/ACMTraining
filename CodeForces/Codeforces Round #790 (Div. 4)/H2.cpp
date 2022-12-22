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
int a[200010];
int f[200010];
int lowbit(int x){
    return x&(-x);
}
void add(int x, int k){
    for(int i = x; i <= n; i += lowbit(i))
        f[i] += k;
}
int ask(int x){
    int sum = 0;
    for(int i = x; i; i -= lowbit(i))
        sum += f[i];
    return sum;
}

void work(){
	cin >> n;
	for(int i=1;i<=n;++i)	cin >> a[i], f[i]=0;
    int res=0;
    long long ans=0;
    for(int i=1; i<=n; ++i){
        ans+=i-1-ask(a[i]-1);
        add(a[i],1);
    }
    cout << ans << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}