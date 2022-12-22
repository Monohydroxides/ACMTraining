#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define SZ(x) ((long long)(x).size())
#define all(a) ((a).begin(),(a).end())
#define debug(a) cout << "Debug: " << #a << ": " << a << "\n"
#define per(i,a,b,c) for(long long i=a;i<b;i+=c)
#define pere(i,a,b,c) for(long long i=a;i<=b;i+=c)
#define rep(i,a,b,c) for(long long i=a;i>b;i-=c)
#define repe(i,a,b,c) for(long long i=a;i>=b;i-=c)
#define mst(a,x) memset(a,x,sizeof a)

using namespace std;

typedef long long LL;
typedef pair<long long, long long> PII;


const long long MOD = 998244353;

long long T;

LL n, x;
map<LL, long long> mp;

long long all1(LL x){
    while(x){
        if(x % 10 != 1) return 0;
        x /= 10;
    }
    return 1;
}

long long countbit(LL x){
    long long cnt = 0;
    while(x){
        cnt ++;
        x /= 10;
    }
    return cnt;
}

typedef struct node{
    long long cnt, opt;
    LL x;
    node(long long a, long long b, LL c){
        cnt = a, opt = b, x = c;
    }
    bool operator< (const node w)const{
        return cnt < w.cnt;
    }
}Node;

void bfs(long long x){
    queue< node > qu;
    qu.push(node(countbit(x), 0, x));
    mp[x] = 1;
    while(qu.size()){
        auto t = qu.front();
        qu.pop();
        if(t.cnt == n){
            cout << t.opt << endl;
            return;
        }
        LL tmp = t.x;
        while(tmp){
            if(tmp % 10 == 0 || tmp % 10 == 1){
                tmp /= 10;
                continue;
            }
            if(countbit(t.x * (tmp % 10)) <= n && (t.x * (tmp % 10)) > 0 && !mp[(t.x * (tmp % 10))])
                qu.push(node(countbit(t.x * (tmp % 10)), t.opt + 1, t.x * (tmp % 10))), mp[(t.x * (tmp % 10))] = 1;
            tmp /= 10;
        }
    }
    cout << -1 << endl;
    return;
}

void work(){
    cin >> n >> x;
    if(all1(x)){
        cout << -1 << endl;
        return;
    }
    bfs(x);
	return;
}

signed main(){
	cin.tie(0);
	T = 1;
	while(T--)	work();
	return 0;
}