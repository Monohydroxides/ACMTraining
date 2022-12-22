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
int a[210][210];

long long calc(int x, int y){
    long long res=a[x][y];
    int nx=x-1,ny=y-1;
    while(nx>=1 && ny >=1)  res+=a[nx][ny], nx--, ny--;
    nx=x+1,ny=y-1;
    while(nx<=n && ny>=1)   res+=a[nx][ny], nx++, ny--;
    nx=x-1,ny=y+1;
    while(nx>=1 && ny<=m)   res+=a[nx][ny], nx--, ny++;
    nx=x+1,ny=y+1;
    while(nx<=n && ny<=m)   res+=a[nx][ny], nx++, ny++;
    return res;
}

void work(){
    cin >> n >> m;
    for(int i=1;i<=n;++i)   for(int j=1;j<=m;++j)   cin >> a[i][j];
    long long res=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            res=max(res, calc(i,j));
        }
    }
    cout << res << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}