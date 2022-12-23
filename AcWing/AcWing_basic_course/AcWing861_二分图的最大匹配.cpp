#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 100010;
int n1, n2, m;
int res;
bool st[N];
int match[N];
int h[N], e[M], ne[M], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = 1;
            if(!match[j] || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n1 >> n2 >> m;
    int a, b;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= m; ++i){
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 1; i <= n1; ++i){
        memset(st, 0, sizeof st);
        if(find(i)) res++;
    }
    cout << res << endl;
    return 0;
}
