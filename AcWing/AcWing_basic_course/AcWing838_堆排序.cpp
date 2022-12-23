#include <bits/stdc++.h>
using namespace std;
int n, m;
int h[100010], sizea;

void down(int x){
    int u = x;
    if(2 * x <= sizea && h[u] > h[x * 2])    u = x * 2;
    if(2 * x + 1 <= sizea && h[u] > h[x * 2 + 1])    u = x * 2 + 1;
    if(u != x){
        swap(h[u], h[x]);
        down(u);   
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> h[i];
        sizea++;
    }
    for(int i = n / 2; i; --i){
        down(i);
    }
    while(m--){
        cout << h[1] << " ";
        swap(h[1], h[sizea]);
        --sizea;
        down(1);
    }
    return 0;
}
