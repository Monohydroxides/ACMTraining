#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;

int st[1010], primes[1010], phi[1010], cnt;
long long pre[1010];

LL work(int x){
    return 1 + 2 * pre[x];
}

int main(){
    cin >> n;
    phi[1] = 1;
    for(int i = 2; i <= 1000; ++i){
        if(!st[i]){
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; i * primes[j] <= 1000; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0){
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
    for(int i = 1; i <= 1000; ++i){
        pre[i] = pre[i - 1] + phi[i];
    }
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        cout << i << " " << x << " " << work(x) << endl;
    }
    return 0;
}
