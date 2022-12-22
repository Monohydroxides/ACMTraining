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
	int n,k;
    cin >> n;
    bool spe[27];
    char str[200010];
    cin >> str;
    int len=strlen(str);
    cin >> k;
    memset(spe,0,sizeof spe);
    for(int i=1;i<=k;++i){
        char ch;
        cin >> ch;
        spe[(ch-'a')]=1;
    }
    int mindist=0, las=0;
    for(int i=0;i<len;++i){
        if(spe[str[i]-'a']){
            mindist=max(mindist,i-las+1);
            las=i;
        }
    }
    if(mindist) mindist--;
    cout << mindist << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}