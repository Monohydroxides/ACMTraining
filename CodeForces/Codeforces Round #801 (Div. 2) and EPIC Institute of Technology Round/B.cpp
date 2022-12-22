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

int a[55];

void work(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }    
    if(n & 1){
        cout << "Mike" << endl;
        return;
    }
    int min1 = 1e9 + 10, min2 = 1e9 + 10;
    int min1loc = -1, min2loc = -1;
    for(int i = 1; i <= n; i += 2){
        if(min1 > a[i]){
            min1 = a[i];
            min1loc = i;
        }
    }
    for(int i = 2; i <= n; i += 2){
        if(min2 > a[i]){
            min2 = a[i];
            min2loc = i;
        }
    }
    // cout << min1 << " " << min2 << endl;
    if(min1 <= min2){
        if(min1 < min2)
            cout << "Joe" << endl;
        else{
            if(min1loc < min2loc){
                cout << "Joe" << endl;
            }else{
                cout << "Mike" << endl;
            }
        }
    }else{
        cout << "Mike" << endl;
    }
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}