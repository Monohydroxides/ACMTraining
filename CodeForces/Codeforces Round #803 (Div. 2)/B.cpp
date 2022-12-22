#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int T;

LL a[200010], dif[200010];

void work(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    if(k == 1){
        cout << (n - 1) / 2 << endl;
        return;
    }else{
        int res = 0;
        for(int i = 2; i <= n - 1; ++i){
            if(a[i] > a[i - 1] + a[i + 1])  ++res;
        }
        cout << res << endl;
    }

}

int main(){
    cin.tie(0);
    cin >> T;
    while(T--)  work();
    return 0;
}