#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

ll cf(ll x, ll k, ll p){
	ll s = 0;
	while(k){
		if(k & 1)	(s += x) %= p;
		(x <<= 1) %= p, k >>= 1;
	}
	return s % p;
}

ll mi(ll x, ll k, ll p){
	ll s = 1;
	while(k){
		if(k & 1)	s = cf(s, x, p) % p;
		x = cf(x, x, p) % p, k >>= 1;
	}
	return s % p;
}

bool millerRabin(ll x){
	ll s = 0, t = x - 1;
	if(x == 2)	return 1;
	if(x < 2 || !(x & 1))	return 0;
	while(!(t & 1)) ++s, t >>= 1;
	for(ll i = 0; i < 10 && primes[i] < x; ++i){
		ll a = primes[i], b = mi(a, t, x);
		for(ll j = 1, k; j <= s; ++j){
			k = cf(b, b, x);
			if(k == 1 && b != 1 && b != x - 1)	return 0;
			b = k;
		}
		if(b != 1)	return 0;
	}
	return 1;
}

void work(){
	ll p, q, enc;
	cin >> p >> q >> enc;
	ll m = p * q - 1;
	map<ll, int> mp;
	for(ll i = 1; i <= m / i; ++i){
		if(m % i == 0){
			if(i > max(p, max(q, enc)) && millerRabin(i)){
				mp[i]++;
			}
			if(m / i > max(p, max(q, enc)) && millerRabin(m / i)){
				mp[m / i]++;
			}
		}
	}

	// for(auto [key, value]: mp){
	// 	cout << key << " ";
	// }
	// cout << endl;

	if(mp.size() != 1){
		cout << "shuanQ" << endl;
	}else{
		map<ll, int>::iterator it = mp.begin();
		cout << enc * q % (*it).first << endl; 
	}
	return;
}

int main(){
	int T;
	cin >> T;
	while(T--)	work();
	return 0;
}