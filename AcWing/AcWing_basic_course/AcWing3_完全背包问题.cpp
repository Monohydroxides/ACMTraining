#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int f[N];
int v[N], w[N];


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    for(int i = 1; i <= n; ++i){
        for(int j = m; j >= v[i]; --j){
            int k = 0;
            while(j - k * v[i] >= 0){
                f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
                k++;
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}
