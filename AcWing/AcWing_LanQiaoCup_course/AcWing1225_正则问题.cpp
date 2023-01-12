#include <bits/stdc++.h>
using namespace std;

int k;
string str;

int dfs () {
    int res = 0 ;
    while (k < str.size()) {
        if (str[k] == '(') {
            k++;
            res += dfs();
            k++;
        } else if (str[k] == ')') {
            break;
        } else if (str[k] == '|') {
            k++;
            res = max(res, dfs());
        } else {
            k++;
            res++;
        }
    }
    return res;
}

int main () {
    cin >> str;
    cout << dfs() << endl;
    return 0 ;
}