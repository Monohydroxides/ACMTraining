#include <bits/stdc++.h>
using namespace std;

int a[100010];
int cnt[1000010], res[1000010];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1; i <= 1000000; ++i){
        if(!cnt[i]) continue;
        for(int j = i; j <= 1000000; j += i){
            res[j] += cnt[i];
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << res[a[i]] - 1 << endl;
    }
    return 0;
}
