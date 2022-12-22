#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, m;
    cin >> n >> m;
    if(n % 2 == 0 && m % 2 == 0) {
        cout << "Tonya" << endl;
    } else if(n % 2 == 1 && m % 2 == 1) {
        cout << "Tonya" << endl;
    } else {
        cout << "Burenka" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        work();
    }
    return 0;
}