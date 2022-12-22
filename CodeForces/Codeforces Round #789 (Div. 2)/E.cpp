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
int a[200010], b[200010];
map<int, int> mpa, mpb;
vector<int> lop;
int st[200010];
int cnt;

void dfs(int x, int ori){
    int bx=b[mpa[x]];
    if(bx==ori) return;
    else{
        if(st[bx]){
            cnt=1;
            return;
        }
        st[bx]=1;
        cnt++;
        dfs(bx, ori);
    }
}

void work(){
	int n;
    cin >> n;
    mpa.clear(), mpb.clear();
    lop.clear();
    for(int i=1;i<=n;++i)   cin >> a[i], mpa[a[i]]=i;
    for(int i=1;i<=n;++i)   cin >> b[i], mpb[b[i]]=i, st[i]=0;
    int l=1,r=n,chg=0;
    for(int i=1;i<=n;++i){
        cnt=1;
        if(st[a[i]])    continue;
        dfs(a[i], a[i]);
        if(cnt==1)  continue;
        lop.pb(cnt);
    }
    long long res=0;
    for(int i=0;i<lop.size();++i){
        long long ans=0;
        int t = lop[i]/2;
        while(t--){
            ans+=2*r;
            r--;
            ans-=2*l;
            l++;
        }
        res+=ans;
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