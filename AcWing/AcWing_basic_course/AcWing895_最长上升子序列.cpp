#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n;
int a[N], f[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
            else    f[i] = max(f[i], 1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; ++i) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}
