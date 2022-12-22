#include <bits/stdc++.h>
using namespace std;

int T;

int n;
int a[300010];
int bigst[300010], bigptr = -1;
int smlst[300010], smlptr = -1;
int h[300010], e[600010], ne[600010], idx;
int dist[300010];
int st[300010];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int spfa(){
    queue<pair<int, int> > q;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    q.push({0,1});
    st[1] = true;
    while(q.size()){
        pair<int,int> p = q.front();
        q.pop();
        int t = p.second;
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + 1){
                dist[j] = dist[t] + 1;
                if(!st[j]){
                    st[j] = true;
                    q.push({dist[j], j});
                }
            }
        }
    }
    return dist[n];
}

void work(){
    cin >> n;
    memset(h, -1, sizeof h), idx = 0;
    memset(st, 0, sizeof st);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(i != n){
            add(i, i + 1), add(i + 1, i);
        }
    }
    for(int i = 1; i <= n; ++i){
        if(bigptr == -1){
            bigst[++bigptr] = i;
        }else{
            while(bigptr >= 0 && a[bigst[bigptr]] < a[i])  bigptr--;
            bigst[++bigptr] = i;
        }
        if(smlptr == -1){
            smlst[++smlptr] = i;
        }else{
            while(smlptr >= 0 && a[smlst[smlptr]] > a[i])  smlptr--;
            smlst[++smlptr] = i;
        }
        
    }
    cout << spfa() << endl;
}

int main(){
    cin.tie(0);
    cin >> T;
    while(T--)  work();
}