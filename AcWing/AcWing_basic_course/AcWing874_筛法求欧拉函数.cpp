#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n;
int primes[N], cnt;
int eular[N];
bool st[N];

void get_eular(){
    eular[1] = 1;
    for(int i = 2; i <= n; ++i){
        if(!st[i]){
            primes[cnt++] = i;
            eular[i] = i - 1;
        }
        for(int j = 0; primes[j] <= n / i; ++j){
            int t = primes[j] * i;
            st[t] = 1;
            if(i % primes[j] == 0){
                eular[t] = eular[i] * primes[j];
                break;
            }
            eular[t] = eular[i] * (primes[j] - 1);
        }
    }
}

int main(){
    cin >> n;
    get_eular();
    long long res = 0;
    for(int i = 1; i <= n; ++i) res += eular[i];
    cout << res << endl;
}
