#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, res = INT_MAX;

int p[N], dst[N];

int find(int x){
    if(x == p[x])   return x;
    int fa = find(p[x]);
    dst[x] += dst[p[x]];
    p[x] = fa;
    return fa;
}

void add(int a, int b){
    int pa = find(a), pb = find(b);
    if(pa == pb){
        res = min(res, dst[a] + dst[b] + 1);
    }else{
        p[pa] = pb;
        dst[pa] = dst[b] + 1;
    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        p[i] = i;
        dst[i] = 0;
    }
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        add(i, x);
    }
    cout << res << endl;
    return 0;
}