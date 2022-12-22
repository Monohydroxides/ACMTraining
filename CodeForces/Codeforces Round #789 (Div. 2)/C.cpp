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

int a[5010];
int presum[5010][5010];

void work(){
	int n;
    cin >> n;
    for(int i=1;i<=n;++i)   for(int j=1;j<=n;++j)   presum[i][j]=0;
    for(int i=1;i<=n;++i){
        cin >> a[i];
        presum[i][a[i]]++;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            presum[i][j]+=presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1];
        }
    }
    long long res=0;
    for(int b=1;b<=n;++b){
        for(int c=b+1;c<=n;++c){
            res+=presum[b-1][a[c]]*(presum[n][a[b]]-presum[c][a[b]]);
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