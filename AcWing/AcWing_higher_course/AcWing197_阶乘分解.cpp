#include <bits/stdc++.h>
using namespace std;

int st[1000010], primes[1000010], cnt;

int main(){
    int n;
    cin >> n;
    for(int i = 2; i <= 1e6; ++i){
        if(!st[i])  primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  break;
        }
    }
    for(int i = 0; i < cnt; ++i){
        if(primes[i] > n){
            break;
        }
        int pri = primes[i];
        int res = 0;
        for(int j = 1; pow(pri, j) <= n; ++j){
            res += (n / (int)pow(pri, j));
        }
        cout << pri << " " << res << endl;
    }
    return 0;
}
