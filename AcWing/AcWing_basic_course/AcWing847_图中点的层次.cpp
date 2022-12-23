#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int h[N], e[2 * N], ne[2 * N], idx;

int n, m;
int vis[N];

void add(int a, int b){
    ne[idx] = h[a], e[idx] = b, h[a] = idx++;    
}

int bfs(int x){
    queue<pair<int, int>> q;
    q.push({x, 0});
    vis[x] = 1;
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        if(now.first == n){
            return now.second;
        }
        for(int i = h[now.first]; i != -1; i = ne[i]){
            if(!vis[e[i]]){
                q.push({e[i], now.second + 1});
                vis[e[i]] = 1;
            }
        }
    }
    return -1;
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs(1) << endl;
    return 0;
}
