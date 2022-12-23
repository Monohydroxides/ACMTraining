#include <bits/stdc++.h>
using namespace std;
int n, l, r, t;
int a[601][601];
int presum[601][601];
int res;
int main(){
    cin >> n >> l >> r >> t;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) cin >> a[i][j];
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + a[i][j];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int d[] = {i + r, j + r, i - r, j - r};
            for(int k = 0; k < 4; ++k){
                if(d[k] < 1)    d[k] = 1;
                if(d[k] > n)    d[k] = n;
            }
            int blocksum = presum[d[0]][d[1]] - presum[d[0]][d[3] - 1] - presum[d[2] - 1][d[1]] + presum[d[2] - 1][d[3] - 1];
            double averg = (double)blocksum / ((double)((d[0] - d[2] + 1) * (d[1] - d[3] + 1)));
            if(averg <= t) ++res;
        }
    }
    cout << res;
    return 0;
}
