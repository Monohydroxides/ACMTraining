#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<int, int> hashm;
int main(){
    cin >> n;
    int a;
    for(int i = 1; i <= n; ++i){
        cin >> a;
        for(int j = 2; j <= a / j; ++j){
            while(a % j == 0){
                a /= j;
                hashm[j]++;
            }
        }
        if(a > 1)   hashm[a]++;
    }
    long long res = 1;
    long long mod = 1e9 + 7;
    for(auto p : hashm){
        long long g = 0;
        for(int i = 0; i <= p.second; ++i){
            g = (g * p.first + 1) % mod;
        }
        res = res * g % mod;
    }
    cout << res << endl;
    return 0;
}
