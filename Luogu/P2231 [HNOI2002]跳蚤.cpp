#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e8 + 10;

int n, m;

LL qmi(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1)   res = (LL) res * a;
        a = (LL) a * a;
        b >>= 1;
    }
    return res;
}
int getmu(int n){
	int res = 1;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0){
			n /= i;
			if (n % i == 0) return 0;
			res = -res;
		}
	}
	if (n > 1) res = -res;
	return res;
}

int main(){
    cin >> n >> m;
    long long res = 0;
    int i = 1;
    for(; i < m / i; ++i){
        if(m % i == 0){
            res += getmu(i) * qmi(m / i, n);
            res += getmu(m / i) * qmi(i, n);
        }
    }
    if(i * i == m)  res += getmu(i) * qmi(i, n);
    cout << res << endl;
    return 0;
}