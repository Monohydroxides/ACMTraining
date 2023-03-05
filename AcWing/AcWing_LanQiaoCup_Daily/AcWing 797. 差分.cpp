#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m, a[N], dif[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), dif[i] = a[i] - a[i - 1];
    for(int i = 1; i <= m; ++i){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        dif[l] += c, dif[r + 1] -= c;
    }
    for(int i = 1; i <= n; ++i){
        a[i] = a[i - 1] + dif[i];
        printf("%d ", a[i]);
    }
    return 0;
}