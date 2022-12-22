#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000000 + 10;

int primes[N], cnt;
bool st[N];
int mu[N];
ll phi[N];
unordered_map<int, int> sum_mu;
unordered_map<int, ll>  sum_phi;

void init() {
    mu[1] = 1, phi[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(!st[i]) {
            primes[cnt++] = i;
            mu[i] = -1;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] * i < N; ++j) {
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            mu[i * primes[j]] = -mu[i];
        }
    }
    for(int i = 1; i < N; ++i) {
        mu[i] += mu[i - 1];
        phi[i] += phi[i - 1];
    }
}

ll get_phi(int x) {
    if(x < N)   return phi[x];
    if(sum_phi[x])  return sum_phi[x];
    ll res = (1ll + x) * x / 2;;
    for(ll l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        res -= (r - l + 1) * get_phi(x / l);
    }
    return sum_phi[x] = res;
}

int get_mu(int x) {
    if(x < N)   return mu[x];
    if(sum_mu[x])   return sum_mu[x];
    int res = 1;
    for(ll l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        res -= (r - l + 1) * get_mu(x / l);
    }
    return sum_mu[x] = res;
}

void work() {
    int n;
    cin >> n;
    cout << get_phi(n) << " " << get_mu(n) << endl;
}

int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    init();
    cin >> T;
    while(T--)  work();
    return 0;
}