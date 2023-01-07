#include <bits/stdc++.h>
using namespace std;

int main () {
    stack<string> stk;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        stk.push(str);
    }
    while (stk.size()) {
        cout << stk.top() << '\n';
        stk.pop();
    }
    return 0;
}