#include <bits/stdc++.h>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

int prim(){
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for(int i = 1; i <= n; ++i){
        int t = -1;
        for(int j = 1; j <= n; ++j) if(!st[j] && (t == -1 || dist[j] < dist[t]))    t = j;
        if(i != 1 && dist[t] == INF)    return INF;
        st[t] = 1;
        if(i != 1)  res += dist[t];
        for(int j = 1; j <= n; ++j) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    int a, b, c;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prim();
    if(t == INF)puts("impossible"); else cout << t << endl;
    return 0;
}
