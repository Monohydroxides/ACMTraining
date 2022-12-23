#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], num[N];
int f[N][N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
        for(int j = 1; j <= num[i]; ++j){
            cin >> v[i][j] >> w[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            f[i][j] = f[i - 1][j];
            for(int k = 1; k <= num[i]; ++k){
                if(j >= v[i][k])    f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
