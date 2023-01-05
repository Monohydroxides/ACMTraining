#include <bits/stdc++.h>
using namespace std;

int main () {
    int res = 0;
    for (int i = 1; i <= 2020; i++) {
        int x = i;
        while (x) {
            if (x % 10 == 2) {
                res++;
            }
            x /= 10;
        }
    }
    cout << res << '\n';
    return 0;
}