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

int a[1010][1010];
int f[1010][1010][2];

void work(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        f[i][0][0] = 1e9 + 10;
        f[i][0][1] = -1e9 - 10;
    }
    for(int j = 1; j <= m; ++j){
        f[0][j][0] = 1e9 + 10;
        f[0][j][1] = -1e9 - 10;
    }
    f[1][1][0] = f[1][1][1] = a[1][1];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i == 1 && j == 1) continue;
            f[i][j][0] = min(f[i - 1][j][0], f[i][j - 1][0]) + a[i][j];
            f[i][j][1] = max(f[i - 1][j][1], f[i][j - 1][1]) + a[i][j];
        }
    }
    if(f[n][m][1] % 2 || f[n][m][0] > 0 || f[n][m][1] < 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}