#include <bits/stdc++.h>
using namespace std;

int n;
int res;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        int l = 1;
        do {
            x -= l;
            l++;
        } while(x >= l);
        res ^= (l - 1);
    }
    if(!res) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}