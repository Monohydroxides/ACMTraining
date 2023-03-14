#include <bits/stdc++.h>
using namespace std;

int a[210], b[210];

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string str;
        cin >> n;
        cin >> str;
        for (int i = 0; i < str.size(); i++) {
            a[i + 1] = (str[i] == 'B' ? 1 : 0);
            b[i + 1] = a[i + 1];
        }
        vector<int> opt1, opt2;
        for (int i = 1; i < n; i++) {
            if (a[i] == 1) {
                a[i] ^= 1;
                a[i + 1] ^= 1;
                opt1.push_back(i);
            }
        }
        if (a[n] == 0) {
            cout << opt1.size() << "\n";
            for (auto it : opt1) {
                cout << it << " ";
            } 
            cout << "\n";
            continue;
        }
        for (int i = 1; i < n; i++) {
            if (b[i] == 0) {
                b[i] ^= 1;
                b[i + 1] ^= 1;
                opt2.push_back(i);
            }
        }
        if (b[n] == 0) {
            cout << -1 << "\n";
        } else {
            cout << opt2.size() << "\n";
            for (auto it : opt2) {
                cout << it << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}