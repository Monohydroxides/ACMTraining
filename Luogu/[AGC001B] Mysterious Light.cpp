#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, x;
    cin >> n >> x;
    cout << 3 * (n -  __gcd(n, x)) << '\n';
    return 0;
}