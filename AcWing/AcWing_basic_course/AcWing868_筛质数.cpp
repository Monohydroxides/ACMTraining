#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n;
bool st[N];
int primes[N];
int cnt;
void get(int x){
    int res = 0;
    for(int i = 2; i <= n; ++i){
        if(!st[i]) {
            res++;
            for(int j = i + i; j <= n; j += i)
                st[j] = 1;
        }
    }
    cout << res << endl;
}

void get2(int x){
    for(int i = 2; i <= x; ++i){
        if(!st[i])  primes[cnt++] = i;
        for(int j = 0; primes[j] <= x / i; ++j){
            st[i * primes[j]] = 1;
            if(i % primes[j] == 0)  break;
        }
    }
    cout << cnt << endl;
}

int main(){
    cin >> n;
    get2(n);
    return 0;
}
