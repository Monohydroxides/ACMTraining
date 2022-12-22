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

const int N=4010;

int T;
int n;
int h[N],e[N],ne[N],w[N],idx;
int cnt=0;

void add(int a, int b){
    e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

int dfs(int x){
    int wei=0;
    for(int i=h[x];~i;i=ne[i]){
        wei+=dfs(e[i]);
    }
    wei+=w[x];
    if(wei==0)  cnt++;
    return wei;
}

void work(){
	cin >> n;
    idx=0;
    memset(h,-1,sizeof h);
    for(int i=2;i<=n;++i){
        int x;
        cin >> x;
        add(x,i);
    }
    char str[4010];
    cin >> str;
    for(int i=1;i<=n;++i){
        if(str[i-1]=='W')   w[i]=1;
        else                w[i]=-1;
    }
    cnt=0;
    dfs(1);
    cout << cnt << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}