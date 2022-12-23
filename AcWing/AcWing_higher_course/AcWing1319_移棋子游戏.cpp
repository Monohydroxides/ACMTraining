#include <bits/stdc++.h>
using namespace std;

const int M = 6010;

int n, m, k;
int mex[2010];
int h[2010], e[M], ne[M], idx;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int work(int x){
    if(mex[x] != -1)    return mex[x];
    map<int, int> t;
    for(int i = h[x]; ~i; i = ne[i]){
        t[work(e[i])] = 1;
    }
    for(int i = 0; i <= 2001; ++i){
        if(!t[i])   return mex[x] = i;
    }
}

int main(){
    memset(h, -1, sizeof h);
    memset(mex, -1, sizeof mex);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 1; i <= n; ++i){
        work(i);
    }
    int res = 0;
    for(int i = 1; i <= k; ++i){
        int x;
        cin >> x;
        res ^= mex[x];
    }
    // for(int i = 1; i <= n; ++i){
    //     cout << mex[i] << " ";
    // }
    // cout << endl;
    if(res)    cout << "win" << endl;
    else        cout << "lose" << endl;
    return 0;
}
