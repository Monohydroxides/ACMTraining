#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n;
int a[500010], cnt[10010];

int main(){
    cin >> n;
    for(int i = 1; i <= n ; ++i)    cin >> a[i];
    n = unique(a + 1, a + 1 + n) - a - 1;
    a[0] = a[n + 1] = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i] > a[i - 1] && a[i] > a[i + 1])  cnt[a[i]] ++;
        else if(a[i] < a[i - 1] && a[i] < a[i + 1])  cnt[a[i]] --;
    }
    int res = 0, ans = 0;
    for(int i = 10000; i > 0; --i){
        res += cnt[i];
        ans = max(res, ans);
    }
    cout << ans << endl;
    return 0;
}
