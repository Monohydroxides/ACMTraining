#include <bits/stdc++.h>
using namespace std;

const int N = 20010, M = 5010;
int n, m;

int fa[N], d[N];

int ptr = 1;
unordered_map<int, int> mp;

int find(int x){
    if(x == fa[x])  return x;
    int root = find(fa[x]);
    d[x] ^= d[fa[x]];
    return fa[x] = root;
}

int main(){
    cin >> n >> m;
    int res = m;
    for(int i = 1; i <= N - 1; ++i) fa[i] = i;
    for(int i = 1; i <= m; ++i){
        int x, y;
        string op;
        cin >> x >> y >> op;
        if(!mp[x - 1])  mp[x - 1] = ptr++;
        if(!mp[y])  mp[y] = ptr++;
        x = mp[x - 1], y = mp[y];
        int t;
        if(op == "even")    t = 0;
        else                t = 1;
        int px = find(x), py = find(y);
        // cout << x << " " << y << " " << px << " " << py << endl;
        if(px != py){
            fa[px] = py;
            d[px] = d[x] ^ d[y] ^ t;
        }else{
            if(d[x] ^ d[y] != t){
                res = i - 1;
                break;
            } 
        }
    }
    cout << res << endl;
    return 0;
}
