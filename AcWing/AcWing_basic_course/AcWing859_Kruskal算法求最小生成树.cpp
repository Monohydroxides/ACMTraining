#include <bits/stdc++.h>
using namespace std;

const int N = 200010, INF = 0x3f3f3f3f;
struct Edge{
    int a, b, w;
    bool operator< (const Edge e)const{
        return w < e.w;
    }
}edges[N];

int n, m;
int p[N / 2];
int find(int x){
    if(x != p[x])   p[x] = find(p[x]);
    return p[x];
}

int kruskal(){
    int cnt = 0, res = 0;
    for(int i = 1; i <= n; ++i) p[i] = i;
    for(int i = 1; i <= m; ++i){
        int a = find(edges[i].a), b = find(edges[i].b);
        if(a != b){
            res += edges[i].w;
            cnt++;
            p[a] = b;
        }
    }
    if(cnt == n - 1)    return res;
    else    return INF;
}

int main(){
    cin >> n >> m;
    int a, b, c;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        if(a == b)  continue;
        edges[i] = {a, b, c};
    }
    sort(edges + 1, edges + m + 1);
    int t = kruskal();
    if (t == INF)   cout << "impossible" << endl;
    else    cout << t << endl;
    return 0;
}
