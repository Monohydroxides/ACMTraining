#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
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

void work(){
	int n, m;
    cin >> n;
    vector<int> a,b;
    int x;
    for(int i = 1; i <= n; ++i) cin >> x, a.pb(x);
    cin >> m;
    for(int i = 1; i <= m; ++i) cin >> x, b.pb(x);
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    int mxa = a[a.size() - 1], mxb = b[b.size() - 1];
    if(mxa < mxb){
        cout << "Bob" << endl;
        cout << "Bob" << endl; 
    }else if(mxa > mxb){
        cout << "Alice" << endl;
        cout << "Alice" << endl;
    }else{
        cout << "Alice" << endl;
        cout << "Bob" << endl;
    }
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}