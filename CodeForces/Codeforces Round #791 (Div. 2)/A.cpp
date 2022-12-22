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

long long n;

void work(){
	cin >> n;
    if(n&1 || n==0){
        cout << -1 << endl;
        return;
    }
    long long res4=0, res6=0;
    long long maxn, minn;
    res4=n/4;
    if(n%4==0){
        minn = res4;
    }else if(n%4 == 2){
        if(res4 >= 1){
            minn = res4;
        }else{
            cout << -1 << endl;
            return;
        }
    }
    res6=n/6;
    if(n%6==0){
        maxn = res6;
    }else if(n%6==2){
        if(res6>=1){
            maxn = res6 + 1;
        }else{
            cout << -1 << endl;
            return;
        }
    }else{
        maxn = res6 + 1;
    }
    cout << maxn << " " << minn << endl;
    return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}