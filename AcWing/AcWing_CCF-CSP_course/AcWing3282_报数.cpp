#include <bits/stdc++.h>
using namespace std;

bool check (int x) {
    while (x) {
        if (x % 10 == 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main () {
    int n;
    cin >> n;
    int loc = 0;
    int cur = 1;
    int cnt = 0;
    int jmp[4];
    memset(jmp, 0, sizeof jmp);
    while (cnt < n) {
        if ((cur % 7 == 0) || !check(cur)) {
            jmp[loc]++;
            cur++;
        } else {
            cur++;
            cnt++;
        }
        loc = (loc + 1) % 4;
    }
    for (int i = 0; i < 4; i++) {
        cout << jmp[i] << '\n';
    }
    return 0;
}