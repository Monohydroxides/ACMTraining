#include <bits/stdc++.h>
using namespace std;

const int N = 25000;

int n, m;
int v[N], w[N], s[N];
int f[N];

int main(){
    cin >> n >> m;
    int a, b, c;
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a >> b >> c;
        int k = 1;
        while(k <= c){
            ++cnt;
            v[cnt] = k * a;
            w[cnt] = k * b;
            c -= k;
            k <<= 1;
        }
        if(c){
            ++cnt;
            v[cnt] = c * a;
            w[cnt] = c * b;
        }
    }
    for(int i = 1; i <= cnt; ++i){
        for(int j = m; j >= v[i]; --j){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
