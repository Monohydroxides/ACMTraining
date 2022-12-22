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

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

void work(){
	int n;
    cin >> n;
    vector<int> a, b, c;
    for(int i = 1; i <= n; ++i){
        int x;
        scanf("%1d", &x);
        a.pb(x);
    }
    reverse(a.begin(), a.end());
    for(int i = 0; i < 10; ++i){
        vector<int> ori;
        ori.pb(1);
        for(int j = 1; j <= n - 1; ++j) ori.pb(i);
        ori.pb(1);
        vector<int> res = sub(ori, a);
        if(res.size() == n){
            reverse(res.begin(), res.end());
            for(int j = 0; j < res.size(); ++j){
                cout << res[j];
            }
            cout << endl;
            break;
        } 
    }
	return;
}

int main(){
	cin >> T;
	while(T--)	work();
	return 0;
}