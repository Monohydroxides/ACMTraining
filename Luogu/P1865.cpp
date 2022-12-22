#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m;
int primes[N], st[N], cnt, sum[N];


void init(){
    for(int i = 2; i < N; ++i){
        if(!st[i]) sum[i]++, primes[cnt++] = i;
        for(int j = 0; primes[j] * i < N; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  break;
        }
    }
    for(int i = 2; i < N; ++i)  sum[i] += sum[i - 1];
}

int main(){
    init();
    cin >> n >> m;
    for(int _ = 1; _ <= n; ++_){
        int l, r;
        cin >> l >> r;
        if(l < 1 || r > m){
            cout << "Crossing the line" << endl;
            continue;
        }
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}