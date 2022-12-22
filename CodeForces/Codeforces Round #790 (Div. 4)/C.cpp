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

int n,m;
int calc(char str1[], char str2[]){
    int dis=0;
    for(int i=0;i<m;++i){
        dis+=abs(str1[i]-str2[i]);
    }
    return dis;
}

void work(){
    cin >> n >> m;
    char str[55][10];
    for(int i=1;i<=n;++i){
        cin >> str[i];
    }
    int dist=INT_MAX;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            dist=min(dist,calc(str[i],str[j]));
        }
    }
    cout << dist << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}