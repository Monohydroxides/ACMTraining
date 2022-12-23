#include <bits/stdc++.h>
using namespace std;

int a[100010], cnt[100010];
int n;
int ans;
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1, j = 1; i <= n; ++i){
        cnt[a[i]]++;
        while(cnt[a[i]] > 1){
            cnt[a[j]]--;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << endl;
    return 0;
}
