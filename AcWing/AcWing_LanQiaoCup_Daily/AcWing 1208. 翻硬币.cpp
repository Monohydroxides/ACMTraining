#include <bits/stdc++.h>
using namespace std;

int main () {
    int res = 0;
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.size() - 1; i++) {
        if (str1[i] != str2[i]) {
            str2[i + 1] = (str2[i + 1] == 'o' ? '*' : 'o');
            res++; 
        }
    }
    cout << res << "\n";
    return 0;
}