#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        b[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= m; ++i){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        b[l] += c;
        b[r + 1] -= c;
    }
    for (int i = 1; i <= n; ++i){
        a[i] = a[i - 1] + b[i];
        printf("%d ", a[i]);
    }
    return 0;
}
