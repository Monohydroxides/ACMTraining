#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 150010;

int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool st[N];

priority_queue<PII, vector<PII>, greater<PII>> heap;

void add(int a, int b, int c){e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;}

int dijkstra(int n){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    heap.push({0, 1});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        if(st[t.second])    continue;
        st[t.second] = true;
        for(int i = h[t.second]; i != -1; i = ne[i])    if(dist[e[i]] > t.first + w[i]) dist[e[i]] = t.first + w[i], heap.push({dist[e[i]], e[i]});
    }
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b, c;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra(n) << endl;
    return 0;
}


