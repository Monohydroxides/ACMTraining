#include <bits/stdc++.h>
using namespace std;

int v, n;

int vi[35];
int f[20010];

int main(){
    scanf("%d%d", &v, &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &vi[i]);
    for(int i = 1; i <= n; ++i){
        for(int j = v; j >= vi[i]; --j){
            f[j] = max(f[j], f[j - vi[i]] + vi[i]);
        }
    }
    cout << v - f[v] << endl;
    return 0;
}