#include <bits/stdc++.h>
using namespace std;

int t;
int fa[30010], d[30010], s[30010];

int find(int x){
    if(x == fa[x])   return x;
    int rot = find(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = rot;
}

int main(){
    for(int i = 1; i <= 30000; ++i) fa[i] = i, d[i] = 0, s[i] = 1;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        char op; int a, b;
        cin >> op >> a >> b;
        if(op == 'M'){
            int pa = find(a), pb = find(b);
            fa[pa] = pb;
            d[pa] = s[pb];
            s[pb] += s[pa];
        }else{
            if(a == b)  {
                cout << 0 << endl;
                continue;
            }
            int pa = find(a), pb = find(b);
            if(pa != pb)    cout << -1 << endl;
            else    cout << abs(d[a] - d[b]) - 1<< endl;
        }
    }
    return 0;
}
