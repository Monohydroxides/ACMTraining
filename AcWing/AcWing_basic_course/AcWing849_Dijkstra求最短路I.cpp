#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, m;
int g[N][N];
int st[N];

int dijkstra(int n){
    int dist[N];
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int j = 1; j <= n; ++j){
        int t = -1;
        for(int i = 1; i <= n; ++i) if(!st[i] && (t == -1 || (dist[i] < dist[t])))  t = i;
        for(int i = 1; i <= n; ++i) dist[i] = min(dist[i], dist[t] + g[t][i]);
        st[t] = 1;
    }
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main(){
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    int a, b, c;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra(n) << endl;
    return 0;
}
