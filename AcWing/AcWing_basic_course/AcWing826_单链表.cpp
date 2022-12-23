#include <bits/stdc++.h>
using namespace std;

int head, e[100010], ne[100010], idx;

void init(){
    head = -1, idx = 0;
    memset(ne, -1, sizeof(ne));
}

void add_head(int x){
    e[idx] = x, ne[idx] = head, head = idx++;
}

void add(int k, int x){
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;    
}

void del(int k){
    ne[k] = ne[ne[k]];
}

int main(){
    init();
    int m;
    cin >> m;
    while(m--){
        char op;
        int k, x;
        cin >> op;
        if(op == 'H'){
            cin >> x;
            add_head(x);
        } else if(op == 'D'){
            cin >> k;
            if(k){
                del(k - 1);
            }else{
                head = ne[head];
            }
        } else{
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for(int i = head; i != -1; i = ne[i]){
        cout << e[i] << ' ';
    }
    return 0;
}
