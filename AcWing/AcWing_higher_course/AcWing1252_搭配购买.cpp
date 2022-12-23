#include <bits/stdc++.h>
using namespace std;

int n, m, wp;
int fa[10010], v[10010], w[10010];
int vis[10010];
int f[10010];

int find(int x){
    if(x == fa[x])  return x;
    else    return fa[x] = find(fa[x]);
}

void un(int x, int y){
    fa[x] = y;
    v[y] += v[x], w[y] += w[x];
}

int main(){
    cin >> n >> m >> wp;
    for(int i = 1; i <= n; ++i) fa[i] = i;
    for(int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;
        w[i] = a, v[i] = b;
    }
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if(pa != pb)    un(pa, pb);
    }
    for(int i = 1; i <= n; ++i){
        int pi = find(i);
        if(pi != i) continue;
        for(int j = wp; j >= w[i]; --j){
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[wp] << endl;
    return 0;   
}
