#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i) a[i] += a[i - 1];
    long long ans = 0;
    for(int i = 1; i < n; ++i) ans += a[i];
    cout << ans << endl;
    return 0;
}
