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

const int N = 110;

int T;

int cnt, n;
vector<PII> res;
int a[N], b[N];

void quicksort(){
    for(int i = n; i >= 1; --i){
        for(int j = 1; j < i; ++j){
            if (a[j] > a[j+1]) {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                res.pb({j, j + 1});
                cnt ++;
            } else if(a[j] == a[j + 1]){
                if(b[j] > b[j + 1]){
                    swap(b[j], b[j + 1]);
                    res.pb({j, j + 1});
                    cnt++;
                }
            }
        }
    }
}

void work(){
    cin >> n;
    cnt = 0;res.clear();
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    quicksort();
    if(cnt <= 10000){
        int ok = 1;
        for(int i = 1; i < n; ++i){
            if(b[i] > b[i + 1] || a[i] > a[i + 1]){
                ok = 0;
                break;
            }
        }
        if(!ok){
            cout << -1 << endl;
        }else{
            cout << cnt << endl;
            for(int i = 0; i < SZ(res); ++i){
                cout << res[i].first << " " << res[i].second << endl;
            }
        }
    }else{
        cout << -1 << endl;
    }
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}