#include <bits/stdc++.h>
using namespace std;

long double constent = ((long double)1 + sqrt(5)) / (long double)2;

int main () {
    int a, b;
    cin >> a >> b;
    if (a < b) {
        swap(a, b);
    }
    if (b == (int)((long double)(a - b) * constent)) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
    }
    return 0;
}