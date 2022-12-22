#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;

int st[40010], primes[40010], phi[40010], cnt;
long long pre[40010];

int main(){
    cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
    phi[1] = 1;
    for(int i = 2; i <= 40000; ++i){
        if(!st[i]){
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; i * primes[j] <= 40000; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0){
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
	for(int i = 1; i <= 40000; ++i)	pre[i] = pre[i - 1] + phi[i];
	cout << pre[n - 1] * 2 + 1;
    return 0;
}