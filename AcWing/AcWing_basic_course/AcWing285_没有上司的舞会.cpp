#include <bits/stdc++.h>
using namespace std;

const int N = 6010;

int n;
int ha[N];
int h[N], e[N], ne[N], idx;
bool has_father[N];
int f[N][2];

void add(int a, int b){e[idx] = b, ne[idx] = h[a], h[a] = idx++;}

void dfs(int x){
    f[x][1] = ha[x];
    for(int i = h[x]; i != -1; i = ne[i]){
        dfs(e[i]);
        f[x][1] += f[e[i]][0];
        f[x][0] += max(f[e[i]][0], f[e[i]][1]);
    }
}

int main(){
    memset(h, -1, sizeof h);
    memset(has_father, 0, sizeof has_father);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> ha[i];
    int k, l;
    for(int i = 1; i <= n - 1; ++i){
        cin >> l >> k;
        add(k, l);
        has_father[l] = 1;
    }
    int root;
    for(int i = 1; i <= n; ++i) if(!has_father[i])  {root = i; break;}
    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}
