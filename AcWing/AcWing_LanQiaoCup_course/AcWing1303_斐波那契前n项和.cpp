#include <bits/stdc++.h>
using namespace std;

const int dim = 3;

int a[dim][dim] = {
    1, 1, 2,
    0, 0, 0,
    0, 0, 0
};

int trans[dim][dim] = {
    1, 1, 1,
    1, 0, 1,
    0, 0, 1
};

int n, mod;

void mul (int a[dim][dim], int b[dim][dim], int c[dim][dim]) {
    int res[dim][dim];
    memset(res, 0, sizeof res);
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            for (int k = 0; k < dim; k++) {
                res[i][j] = (res[i][j] + (long long) b[i][k] * c[k][j] % mod) % mod;
            }
        }
    }
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            a[i][j] = res[i][j];
        }
    }
}

int main () {
    cin >> n >> mod;
    if (n <= 2) {
        cout << n % mod << '\n';
        return 0;
    }
    n -= 2;
    while (n) {
        if (n & 1) mul(a, a, trans);
        mul(trans, trans, trans);
        n >>= 1;    
    }
    cout << a[0][2] << '\n';
    return 0;
}