#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int l[N], r[N], e[N], idx;

void init(){
    memset(r, -1, sizeof(r)), memset(l, -1, sizeof(l));
    r[0] = 1, l[1] = 0, idx = 2;
}

void add(int k, int x){
    e[idx] = x, r[idx] = r[k], l[idx] = k, l[r[k]] = idx, r[k] = idx++;
}

void del(int k){
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

int main(){
    int m;
    cin >> m;
    init();
    while(m--){
        string opt;
        cin >> opt;
        int k, x;
        if(opt == "R"){
            cin >> x;
            add(l[1], x);
        } else if(opt == "L"){
            cin >> x;
            add(0, x);
        } else if(opt == "D"){
            cin >> k;
            del(k + 1);
        } else if(opt == "IL"){
            cin >> k >> x;
            add(l[k + 1], x);
        } else{
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    for(int i = r[0]; i != 1; i = r[i]){
        cout << e[i] << ' ';
    }
    return 0;
}
