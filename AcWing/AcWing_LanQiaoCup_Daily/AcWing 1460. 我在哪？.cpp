#include <bits/stdc++.h>
using namespace std;

int n;
string str;

bool check (int x) {
    unordered_map<string, int> cnt;
    for (int i = 0; i < n - x + 1; i++) {
        if (cnt[str.substr(i, x)]) return false;
        else cnt[str.substr(i, x)]++;
    }
    return true;
}

int main () {
    cin >> n >> str;
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
    return 0;
}