#include <bits/stdc++.h>
using namespace std;

int n;

void calc (int x) {
    vector<int> ans;
    while (x) {
        ans.push_back(x % n);
        x /= n;
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i;
    }
}

int main () {
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            calc(i * j);
            cout << " ";
        }
        cout << '\n';
    }
    return 0;
}