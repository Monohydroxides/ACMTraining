#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int k, x;
int primes[1010], st[1010], cnt;
int sum[1010];

void get_primes(){
    for(int i = 2; i <= 1000; ++i){
        if(!st[i])  primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= 1000; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  break;
        }
    }
}

int get(int n, int p){
    int res = 0;
    while(n){
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> & a, int b){
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size(); ++i){
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(t){
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int qmi(int a, int b, int mod){
    int res = 1 % mod;
    while(b){
        if(b & 1)   res = (LL) res * a % mod;
        a = (LL) a * a % mod;
        b >>= 1;
    }
    return res;
}



void C(int a, int b){
    for(int i = 0; i < cnt; ++i){
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }
    vector<int> res;
    res.push_back(1);
    for(int i = 0; i < cnt; ++i){
        for(int j = 0; j < sum[i]; ++j){
            res = mul(res, primes[i]);
        }   
    }
    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size(); ++i){
        cout << res[i];
    }
    cout << endl;
}

int main(){
    cin >> k >> x;
    get_primes();
    int gx = qmi(x, x, 1000);
    C(gx - 1, k - 1);
    return 0;
}
