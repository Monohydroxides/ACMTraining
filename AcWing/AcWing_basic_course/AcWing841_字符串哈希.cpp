#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 131;
ULL h[N], p[N];

ULL get(int a, int b){
    return h[b] - h[a - 1] * p[b - a + 1];
}

int main(){
    int n, m;
    string str;
    cin >> n >> m;
    cin >> str;
    int l1, r1, l2, r2;
    p[0] = 1;
    for(int i = 1; i <= n; ++i){
        p[i] = p[i - 1] * P;
    }
    for(int i = 1; i <= n ; ++i){
        h[i] = h[i - 1] * P + str[i - 1];
    }
    while(m--){
        cin >> l1 >> r1 >> l2 >> r2;
        if(get(l1, r1) == get(l2, r2))  puts("Yes");
        else    puts("No");
    }    
    return 0;
}
