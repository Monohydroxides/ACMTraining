#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100010;

LL a0, a1, b0, b1;
map<LL, int> mp;
int st[N], primes[N], cnt;
int res;

LL gcd(LL x, LL y){
    return y ? gcd(y, x % y): x;
}

LL lcm(LL x, LL y){
    return x * y / gcd(x, y);
}

LL qmi(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1)   res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void dfs(int u, vector<pair<int,int> > & fact, LL las){
    if(gcd(las, a0) == a1 && lcm(las, b0) == b1){
        if(!mp[las])    res++, mp[las] = 1;
    }
    if(gcd(a0, las) > a1 || las > b1) return;
    if(u >= fact.size())    return;
    for(int i = 0; i <= fact[u].second; ++i){
        dfs(u + 1, fact, las * qmi((LL)fact[u].first, (LL)i));
    }
}

void work(){
    res = 0;
    mp.clear();
    cin >> a0 >> a1 >> b0 >> b1;
    vector<pair<int,int> > fact;
    LL p = b1;
    for(int i = 0; i < cnt; ++i){
        int fcnt = 0;
        while(b1 % primes[i] == 0){
            fcnt++;
            b1 /= primes[i];
        }
        if(fcnt)    fact.push_back({primes[i], fcnt});
    }
    if(b1 > 1)  fact.push_back({b1, 1});
    b1 = p;
    dfs(0, fact, 1);
    cout << res << endl;
}

int main(){

    for(int i = 2; i <= 100000; ++i){
        if(!st[i])  primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= 100000; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  break;
        }
    }

    int t;
    cin >> t;
    while(t--)  work();

    return 0;
}
