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
int n,q;
int presum[150010];
int a[150010];

void work(){
	cin >> n >> q;
    for(int i=1;i<=n;++i)   cin >> a[i];
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;++i)   presum[i]=presum[i-1]+a[i];
    presum[n+1]=INT_MAX;
    for(int i=1;i<=q;++i){
        int x;
        cin >> x;
        int l=1,r=n+1;
        while(l<r){
            int mid=l+r>>1;
            if(presum[mid]>=x)  r=mid;
            else                l=mid+1;
        }
        if(l>n)     cout << -1 << endl;
        else        cout << l << endl;
    }
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}