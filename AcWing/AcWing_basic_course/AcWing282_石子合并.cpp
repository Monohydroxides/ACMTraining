#include <bits/stdc++.h>
using namespace std;

int n;
int pre[310];
int f[310][310];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> pre[i];
    for(int i = 1; i <= n; ++i) pre[i] += pre[i - 1];
    for(int len = 2; len <= n; ++len){
        for(int i = 1; i + len - 1 <= n; ++i){
            int l = i, r = len + i - 1;
            f[l][r] = 0x3f3f3f3f;
            for(int k = l; k < r; ++k){
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + pre[r] - pre[l - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
