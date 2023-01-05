#include <bits/stdc++.h>
using namespace std;

int main () {
    int cur = 1;
    int now = 4;
    for (int i = 2; i <= 20; i++) 
        cur += now, now += 4;
    cout << cur << '\n';
    return 0;
}
