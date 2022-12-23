#include <bits/stdc++.h>
using namespace std;
int p[100010];
int find(int x){
    if(x != p[x])   p[x] = find(p[x]);
    return p[x];
}

int main(){
    int m, n;
    cin >> n >> m;
    string opt;
    int a, b;
    for(int i = 1; i <= n; ++i){
        p[i] = i;
    }
    while(m--){
        cin >> opt >> a >> b;
        if(opt[0] == 'M'){
            p[find(a)] = find(b);
        } else {
            if(find(a) == find(b)){
                cout << "Yes" << endl;
            } else cout << "No" << endl;
        }
    }
    return 0;
}
