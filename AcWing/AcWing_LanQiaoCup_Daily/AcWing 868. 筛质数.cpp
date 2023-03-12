#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

vector<int> primes;
bool st[N];

int main () {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes.push_back(i);
        }
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    cout << primes.size() << "\n";
}