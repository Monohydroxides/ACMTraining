#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    // int f[1010][1010];
    // memset(f, 0, sizeof f);
    // for(int i = 1; i <= n; ++i) f[i][0] = 1;
    // for(int i = 1; i <= n; ++i){
    //     for(int j = 1; j <= n; ++j){
    //         f[i][j] += f[i - 1][j] % mod;
    //         if(j >= i)  f[i][j] += f[i][j - i] % mod;
    //     }
    // }
    // cout << f[n][n] << endl;

    int f[1010];
    memset(f, 0, sizeof f);
    f[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            f[j] = (f[j] + f[j - i] % mod) % mod; 
        }
    }
    cout << f[n] << endl;

    return 0;
}
