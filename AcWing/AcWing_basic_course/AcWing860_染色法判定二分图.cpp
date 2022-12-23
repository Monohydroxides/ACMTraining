#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 200010;
int h[N], e[M], ne[M], idx;
int st[N];
int n, m;
bool flag = true;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int x, int c){
    st[x] = c;
    for(int i = h[x]; i != -1; i = ne[i]){
        if(!st[e[i]])  dfs(e[i], 3 - c);
        else if(st[e[i]] == c)  flag = false;
    }
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    for(int i = 1; i <= n; ++i){
        if(!st[i])  dfs(i, 1);
    }
    if(flag)    puts("Yes");
    else    puts("No");
    return 0;
}
