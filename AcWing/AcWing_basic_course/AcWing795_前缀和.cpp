#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[100010], n, m;
    long long s[100010];
    a[0] = s[0] = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= m; ++i){
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
