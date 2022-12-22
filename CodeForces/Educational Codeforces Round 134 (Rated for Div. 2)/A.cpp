#include <bits/stdc++.h>
using namespace std;

void work() {
    string str1, str2;
    map<char, int> mp;
    cin >> str1 >> str2;
    mp[str1[0]]++, mp[str1[1]]++, mp[str2[0]]++, mp[str2[1]]++;
    if (mp.size() == 1) {
        cout << 0 << '\n';
    } else if (mp.size() == 2) {
        cout << 1 << '\n';
    } else if (mp.size() == 3) {
        cout << 2 << '\n';
    } else {
        cout << 3 << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}