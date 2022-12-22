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
int n,k;

void work(){
    cin >> n >> k;
    map<int,int> mp;
    vector<int> yms;
    for(int i=1;i<=n;++i) {
        int x;
        cin >> x;
        mp[x]++;
        yms.pb(x);
    }
    sort(yms.begin(),yms.end());
    yms.erase(unique(yms.begin(),yms.end()),yms.end());
    int res=1;
    int locl=-1,locr=0;
    for(int l=0;l<yms.size();++l){
        int r=l;
        while(r<yms.size() && mp[yms[r]]>=k && (r==l || yms[r]-yms[r-1]<=1)) ++r;
        if(res<r-l+1){
            res=r-l+1;
            locl=l, locr=r-1;
        }
        if(l!=r)    l=r-1;
    }
    if(locl==-1){
        cout << -1 << endl;
        return;
    }
    cout << yms[locl] << " " << yms[locr] << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;

}