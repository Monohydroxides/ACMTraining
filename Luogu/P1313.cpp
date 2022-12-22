#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int mod = 10007;

int qmi(int a, int b){
	int res = 1;
	while(b){
		if(b & 1)	res = (LL) res * a % mod;
		a = (LL) a * a % mod;
		b >>= 1;
	}
	return res;
}

int comb(int a, int b){
	int res = 1;
	for(int i = 1, j = a; i <= b; ++i, --j){
		res = (LL) res * j % mod;
		res = (LL) res * qmi(i, mod - 2) % mod;
	}
	return res;
}

int C(int a, int b){
	if(a < mod && b < mod)	return comb(a, b);
	else	return comb(a % mod, b % mod) * (LL)C(a / mod, b / mod) % mod;
}

int main(){
	int a, b, k, n, m;
	cin >> a >> b >> k >> n >> m;
	cout << qmi(a, n) * qmi(b, m) % mod * C(k, n) % mod;
	return 0;
}