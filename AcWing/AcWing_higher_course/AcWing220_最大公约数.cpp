#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e7 + 5;

int n;
int st[N], primes[N], phi[N], cnt;
LL pre[N];
LL res = 0;


int main(){
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    phi[1] = 0;
    for(int i = 2; i <= 1e7; ++i){
        if(!st[i]){
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] * i <= 1e7; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0){
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
    for(int i = 1; i <= 1e7; ++i){
        pre[i] = pre[i - 1] + phi[i];
    }
    for(int i = 0; i < cnt; ++i){
        if(primes[i] > n)   break;
        res += 2 * pre[n / primes[i]] + 1;
    }
    cout << res << endl;
    return 0;
}
