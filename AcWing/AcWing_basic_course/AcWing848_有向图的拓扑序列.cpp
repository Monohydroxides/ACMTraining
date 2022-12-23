#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N], q[N];

void add(int a, int b) {e[idx] = b, ne[idx] = h[a], h[a] = idx++;}

bool topsort(){
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; ++i){
        if(!d[i]){q[++tt] = i;}
    }
    while(hh <= tt){
        int i = q[hh++];
        for(int s = h[i]; s != -1; s = ne[s]){
            int j = e[s];
            --d[j];
            if(!d[j]){
                q[++tt] = j;
            }
        }
    }
    return tt == n - 1;
}

int main(){
    memset(h, -1, sizeof h);
    int a, b;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b;
        add(a, b);
        ++d[b];
    }
    if(topsort()){
        for(int i = 0; i < n; ++i)  cout << q[i] << " ";
    } else {
        cout << -1 << endl;
    }
    return 0;
}
