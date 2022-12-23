#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 10005;

struct edge{
    int a, b, w;
}edges[M];

int n, m, k;
int dist[N], backup[N];

void bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 1; i <= k; ++i){
        memcpy(backup, dist, sizeof dist);
        for(int j = 1; j <= m; ++j){
            if(dist[edges[j].b] > backup[edges[j].a] + edges[j].w)    dist[edges[j].b] = backup[edges[j].a] + edges[j].w;
        }
    }
    if(dist[n] > 0x3f3f3f3f / 2)    puts("impossible");
    else    cout << dist[n] << endl;
}

int main(){
    cin >> n >> m >> k;
    int a, b, w;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b >> w;
        edges[i].a = a, edges[i].b = b, edges[i].w = w;
    }
    bellman_ford();
    return 0;
}
