#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100010, mod = 998244353;

int n, m;
int h[N], e[10 * N], ne[10 * N], idx;
ll cnt[N], len[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u){
    if(cnt[u])  return;
    cnt[u] = 1;
    for(int i = h[u]; ~i; i = ne[i]){
        int v = e[i];
        dfs1(v);
        cnt[u] = (cnt[u] + cnt[v]) % mod;
        len[u] = (len[u] + len[v] + cnt[v]) % mod;
    }
}

ll qmi(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 1; i <= n; ++i){
        if(!cnt[i]){
            dfs1(i);
        }
    }
    // for(int i = 1; i <= n; ++i) cout << cnt[i] << endl;
    ll resp = 0, resq = 0;
    for(int i = 1; i <= n; ++i){
        resp = (resp + cnt[i]) % mod, resq = (resq + len[i]) % mod;
    }
    cout << resq * qmi(resp, mod - 2) % mod << endl;
    return 0;
}