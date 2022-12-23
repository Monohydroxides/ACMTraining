#include <bits/stdc++.h>
using namespace std;

int n;

int st[100010], a[100010], primes[100010], cnt;

int main(){
    cin >> n;
    int res = 1;
    for(int i = 2; i <= n + 1; ++i){
        if(!st[i])  a[i] = 1, primes[cnt++] = i;
        for(int j = 0; i * primes[j] <= n + 1; ++j){
            st[primes[j] * i] = 1;
            res = 2;
            a[primes[j] * i] = 2;
            if(i % primes[j] == 0)   break;
        }
    }
    cout << res << endl;
    for(int i = 2; i <= n + 1; ++i){
        cout << a[i] << " ";
    }
    return 0;
}
