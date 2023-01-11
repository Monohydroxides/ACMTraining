#include <bits/stdc++.h>
using namespace std;

int n;

int main () {
    cin >> n;
    for (int state = 0; state < (1 << n); state++) {
        for (int i = 1; i <= n; i++) {
            if ((state >> (i - 1)) & 1) {
                cout << i << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}