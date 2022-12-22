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

int a[110];

void work(){
	int n;
    cin >> n;
    int cnt=0,has_pir=0;
    map<int, int> mp;
    for(int i=1;i<=n;++i){
        cin >> a[i];
        if(a[i]==0)     cnt++;
        if(mp[a[i]])    has_pir=1;
        mp[a[i]]=1;
    }
    if(cnt==0){
        if(has_pir){
            cout << n << endl;
        }else{
            cout << n + 1 << endl;
        }
    }else{
        cout << n-cnt << endl;
    }
    // cout << cnt << " " << has_pir << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}