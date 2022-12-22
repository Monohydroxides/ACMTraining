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

const int MOD = 1e9+7;

int T;

const int N = 500010;

int a[N],b[N],c[N];
int cnt;
map<int,int> est;
map<int,int> mpa,mpb;

void add(int x, int ori){
    int bx=b[mpa[x]];
    if(bx==ori) return;
    else{
        if(est[bx]) {
            cnt=1;
            return;
        }
        est[bx]=1;
        cnt++;
        add(bx,ori);
    }
}
 
void work(){
	int n;
    cin >> n;
    est.clear();
    mpa.clear(),mpb.clear();
    for(int i=1;i<=n;++i)   cin >> a[i],mpa[a[i]]=i;
    for(int i=1;i<=n;++i)   cin >> b[i],mpb[b[i]]=i;
    for(int i=1;i<=n;++i)   cin >> c[i],est[c[i]]=1;
    long long res=1;
    for(int i=1;i<=n;++i){
        if(!est[i]) {
            est[i]=1;
            cnt=1;
            add(i,i);
            cnt=min(cnt,2);
            res=res*cnt%MOD;
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