#include<bits/stdc++.h>
using namespace std;

long long n;

int main () {
    cin >> n;
    vector<int> res;
    while (n > 0) {
        int cur = n % 26;
        if (!cur) cur = 26;
        res.push_back(cur);
        n = (n - 1) / 26;
    }
    reverse(res.begin(), res.end());
    for (auto i : res) cout << (char) ('a' + i - 1);
}
