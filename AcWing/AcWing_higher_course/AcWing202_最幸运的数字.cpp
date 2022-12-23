#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL x, LL y){
    return y ? gcd(y, x % y) : x;
}

LL phi(LL c){
    LL res = c;
    for(LL i = 2; i <= c / i; ++i){
        if(c % i == 0){
            while(c % i == 0)   c /= i;
            res = res / i * (i - 1);
        }
    }
    if(c > 1)   res = res / c * (c - 1);
    return res;
}

LL qmul(LL a, LL b, LL c){
    LL res = 0;
    while(b){
        if(b & 1)   res = (res + a) % c;
        a = (a + a) % c;
        b >>= 1;
    }
    return ((res % c) + c) % c;
}

LL qmi(LL a, LL b, LL c){
    LL res = 1 % c;
    while(b){
        if(b & 1)   res = qmul(res, a, c);
        a = qmul(a, a, c);
        b >>= 1;
    }
    return ((res % c) + c) % c;
}

LL work(LL l){
    LL d = gcd(8, l);
    LL c = 9 * l / d;
    LL x = phi(c);
    if(c % 5 == 0 || c % 2 == 0){
        return 0;
    }
    LL res = x;
    for(LL i = 1; i <= x / i; ++i){
        if(x % i == 0){
            if(qmi(10, i, c) == 1)      res = min(res, i);
            if(qmi(10, x / i, c) == 1)  res = min(res, x / i);
        }
    }
    return res;
}

int main(){
    LL l;
    int i = 1;
    while(cin >> l, l){
        LL res = work(l);
        cout << "Case " << i << ": " << res << endl;
        i++;
    }
    return 0;
}
