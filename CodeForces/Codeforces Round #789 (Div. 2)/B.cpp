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

void work(){
	int n;
    cin >> n;
    char str[200010];
    cin >> str;
    int cnt=0;
    for(int i=0;i<n;++i){
        int j=i;
        while(str[i]==str[j]){
            ++j;
        }
        int len=j-i;
        if(len&1){
            cnt++;
            if(str[j]=='1') str[j]='0';
            else            str[j]='1';
            i=j;
            continue;
        }
        i=j-1;
    }
    cout << cnt << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}