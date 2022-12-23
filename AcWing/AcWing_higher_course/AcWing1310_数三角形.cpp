#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n, m;

LL gcd(LL a, LL b){
    return b ? gcd(b, a % b): a;
}

LL C(LL a, LL b){
    LL res = 1;
    for(LL i = 1; i <= b; ++i){
        res = res * a;
        a--;
    }
    for(LL i = 1; i <= b; ++i){
        res /= i;
    }
    return res;
}

int main(){
    cin >> m >> n;
    LL res = C((n + 1) * (m + 1), 3) - (m + 1) * C((n + 1), 3) - (n + 1) * C(m + 1, 3);
    for(LL i = 1; i <= n; ++i){
        for(LL j = 1; j <= m; ++j){
            res -= 2 * (n - i + 1) * (m - j + 1) * (gcd(i, j) - 1);
        }
    }
    cout << res << endl;
    return 0;
}
