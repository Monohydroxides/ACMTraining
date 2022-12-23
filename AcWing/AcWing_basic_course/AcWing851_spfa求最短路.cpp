#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], w[N], idx;
int n, m;
bool st[N];
int dist[N];

void add(int a, int b, int c){e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;}

int spfa(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        st[t] = 0;
        for(int i = h[t]; i != -1; i = ne[i]){
            if(dist[e[i]] > dist[t] + w[i]) {
                dist[e[i]] = dist[t] + w[i];
                if(!st[e[i]])   q.push(e[i]), st[e[i]] = 1;
            }
        }
    }
    if(dist[n] >= 0x3f3f3f3f / 2)   return -0x3f3f3f3f;
    else    return dist[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    int a, b, c;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int t = spfa();
    if(t == -0x3f3f3f3f) cout << "impossible" << endl;
    else    cout << t << endl;
    return 0;
}
