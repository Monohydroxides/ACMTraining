#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int e[2 * N], ne[2 * N], h[N], w[N * 2], idx;
int outd[N];
double f[N];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

double dp(int x){
    if(f[x] >= 0)   return f[x];
    f[x] = 0;
    for(int i = h[x]; ~i; i = ne[i]){
        f[x] += (w[i] + dp(e[i])) / outd[x];
    }
    return f[x];
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        outd[a]++;
    }
    for(int i = 1; i <= n; ++i) f[i] = -1;
    printf("%.2lf\n", dp(1));
    return 0;
}
