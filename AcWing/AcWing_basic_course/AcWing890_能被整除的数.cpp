#include <bits/stdc++.h>
using namespace std;

int n, m;
int primes[20];

int main(){
    cin >> n >> m;
    int res = 0;
    for(int i = 1; i <= m; ++i) cin >> primes[i];
    for(int i = 1; i < 1 << m; ++i){
        int cnt = 0, ans = 1;
        for(int j = 1; j <= m; ++j){
            if(i >> (j - 1) & 1){
                if((long long)ans * primes[j] > n){
                    ans = -1;
                    break;
                }
                ans *= primes[j];
                cnt++;
            }
        }
        if(ans == -1)   continue;
        if(cnt % 2) res += n / ans;
        else    res -= n / ans;
    }
    cout << res << endl;
    return 0;
}
