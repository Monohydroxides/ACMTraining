#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll b, p, k;
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=", b, p, k);
    ll base = b, ans = 1;
    while (p > 0) {
        if (p & 1) {
            ans *= base;
            ans %= k;
        }
        p >>= 1;
        base *= base;
        base %= k;
    }
    ans %= k;
    printf("%lld", ans);
    return 0;
}