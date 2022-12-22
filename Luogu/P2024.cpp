#include <bits/stdc++.h>
using namespace std;

const int N = 50010;

int n, k;
int fa[N], d[N];
int st[3][3] = {1,2,0,0,1,2,2,0,1};
int st2[3] = {2, 0, 1};
int st3[3][3] = {0, 1, 2, 2, 0, 1, 1, 2, 0}; 

int find(int x){
    if(x == fa[x])  return x;
    int root = find(fa[x]);
    d[x] = (d[x] + d[fa[x]]) % 3;
    return fa[x] = root;
}

int main(){
    int res = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) fa[i] = i;
    for(int i = 1; i <= k; ++i){
        int x, y, D;
        cin >> D >> x >> y;
        if(x > n || y > n){
            res ++;
            continue;
        }
        if(D == 2 && x == y){
            res ++;
            continue;
        }
        if(D == 1){
            int px = find(x), py = find(y);
            if(px != py){
                fa[px] = py;
                d[px] = st3[d[x]][d[y]];
            }else{
                if(d[x] != d[y]){
                    res ++;
                }
            }
        }else{
            int px = find(x), py = find(y);
            if(px != py){
                fa[px] = py;
                d[px] = st[d[x]][d[y]];
            }else{
                if(!(st2[d[x]] == d[y]))   res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}