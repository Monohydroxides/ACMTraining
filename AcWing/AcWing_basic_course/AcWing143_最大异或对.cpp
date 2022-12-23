#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int son[N * 31][2];
int a[N];
int idx;

void add(int x){
    int p = 0;
    for(int i = 31; i >= 0; --i){
        int cur = x >> i & 1;
        if(!son[p][cur])    son[p][cur] = ++idx;
        p = son[p][cur];
    }
}

int query(int x){
    int p = 0;
    int res = 0;
    for(int i = 31; i >= 0; --i){
        int cur = x >> i & 1;
        if(son[p][!cur])    p = son[p][!cur], res += 1 << i;
        else    p = son[p][cur];
    }
    return res;
}

int main(){
    int n;
    int ans = -1;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        add(a[i]);
    }
    for(int i = 0; i < n; ++i){
        ans = max(ans, query(a[i]));
    }
    cout << ans << endl;
    return 0;
}
