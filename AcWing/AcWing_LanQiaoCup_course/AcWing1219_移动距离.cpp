#include <bits/stdc++.h>
using namespace std;

int w, n, m;

int main () {
    cin >> w >> n >> m;
    int rown = (n - 1) / w + 1, rowm = (m - 1) / w + 1;
    // cout << rown << " " << rowm << '\n';
    int coln = (n - 1) % w, colm = (m - 1) % w;
    // cout << coln << " " << colm << '\n';
    int res = abs(rown - rowm);
    if (abs(rown - rowm) & 1) {
        res += abs(w - 1 - coln -  colm);
    } else {
        res += abs(coln - colm);
    }
    cout << res << '\n';
    return 0;
}