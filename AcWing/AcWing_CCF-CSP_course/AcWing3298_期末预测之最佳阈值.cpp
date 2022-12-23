#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[100010];
int cnt[2][100010];


int main(){
    cin >> n;
    int cnt1 = 0;
    for(int i = 1; i <= n; ++i){
        int c, d;
        cin >> c >> d;
        a[i].first = c, a[i].second = d;
        if(d)   cnt1++;
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i){
        if(a[i].second)     cnt[1][i] = cnt[1][i - 1] + 1, cnt[0][i] = cnt[0][i - 1];
        else                cnt[0][i] = cnt[0][i - 1] + 1, cnt[1][i] = cnt[1][i - 1];
    }
    int res = 0, ans = 0;
    for(int i = 1; i <= n; ++i){
        int j = i;
        while(j <= n + 1 && a[i].first == a[j].first)   ++j;
        if(res <= cnt[0][i - 1] + cnt1 - cnt[1][i - 1]){
            res = cnt[0][i - 1] + cnt1 - cnt[1][i - 1];
            ans = a[i].first;
        }
        i = j - 1;
    }
    cout << ans << endl;
    return 0;
}
