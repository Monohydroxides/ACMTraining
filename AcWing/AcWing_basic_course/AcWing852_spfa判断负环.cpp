#include <bits/stdc++.h>
using namespace std;

const int N = 2005, M = 10010;

int dist[N], cnt[N];
bool st[N];

int n, m;
int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool spfa(){
    queue<int> q;
    for(int i = 1; i <= n; ++i) q.push(i), st[i] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        st[t] = 0;
        for(int i = h[t]; i != -1; i = ne[i]){
            if(dist[e[i]] > dist[t] + w[i]){
                dist[e[i]] = dist[t] + w[i];
                cnt[e[i]] = cnt[t] + 1;
                if(cnt[e[i]] >= n)  return true;
                if(!st[e[i]])   q.push(e[i]), st[e[i]] = 1;
            }
        }
    }
    return false;
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b, c;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        add(a, b, c);
    }
    if(spfa())  puts("Yes");
    else    puts("No");
    return 0;
}
