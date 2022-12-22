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

long long poww(long long a, long long b){
    long long ret = 1;
    for(; b; b >>= 1){
        if(b & 1) ret = (long long)ret * a;
        a = a * a;
    }
    return ret;
}

void work(){
	char str1[55], str2[55];
    cin >> str1 >> str2;
    int cnt=0;
    if(strlen(str2)==1 && str2[0]=='a'){
        cout << 1 << endl;
        return;
    }
    for(int i=0;i<strlen(str2);++i){
        if(str2[i]=='a')    cnt++;
        if(cnt > 1 || (cnt==1 && strlen(str2)>1)){
            cout << -1 << endl;
            return;
        }
    }
    long long len1 = strlen(str1);
    long long len2 = strlen(str2);
    cout << poww(2,len1) << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}