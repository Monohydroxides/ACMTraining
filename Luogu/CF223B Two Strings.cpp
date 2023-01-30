#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int l[N], r[N];
int las[30];

int main () {
    string str1, str2;
    cin >> str1 >> str2;
    int n1 = str1.size(), n2 = str2.size();
    for (int i = 0, j = 0; i < n1; ++i) {
        if (str1[i] == str2[j]) {
            l[i] = j;
            las[str1[i] - 'a'] = j;
            j += 1;
        } else {
            l[i] = las[str1[i] - 'a'];
        }
    }
    memset(las, 0x3f, sizeof las);
    for (int i = n1 - 1, j = n2 - 1; i >= 0; --i) {
        if (str1[i] == str2[j]) {
            r[i] = j;
            las[str1[i] - 'a'] = j;
            j -= 1;
        } else {
            r[i] = las[str1[i] - 'a'];
        }
    }
    for (int i = 0; i < n1; ++i) {
        if (l[i] < r[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}