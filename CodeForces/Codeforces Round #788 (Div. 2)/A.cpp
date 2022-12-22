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
int a[100010];

void work(){
	int n, cnt=0;
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> a[i];
        if(a[i]<0)  cnt++;
    }
    int ok=1;
    for(int i=1;i<cnt;++i){
        if(abs(a[i])<abs(a[i+1]))   ok=0;
    }
    for(int i=cnt+1;i<n;++i){
        if(abs(a[i])>abs(a[i+1]))   ok=0;
    }
    if(ok)  cout << "YES" << endl;
    else    cout << "NO"  << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}