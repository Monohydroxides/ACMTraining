#include <bits/stdc++.h>
using namespace std;

int main () {
    int T;
    cin >> T;
    string str;
    while (T--) {
        cin >> str;
        stack<int> stk;
        for (int i = 0; i < 7; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                stk.push(str[i] - '0');
            } else {
                if (str[i] == 'x' || str[i] == '/') {
                    int las = stk.top();
                    stk.pop();
                    int nxt = str[i + 1] - '0';
                    if (str[i] == 'x') {
                        stk.push(las * nxt);
                    } else {
                        stk.push(las / nxt);
                    }
                    i++;
                } else {
                    if (str[i] == '+') {
                        stk.push(-1);
                    } else {
                        stk.push(-2);
                    }
                }
            }
        }
        deque<int> dq;
        while (stk.size()) {
            dq.push_front(stk.top());
            stk.pop();
        }
        int ans = 0;
        while (dq.size()) {
            if (dq.front() >= 0) {
                ans = dq.front();
                dq.pop_front();
            } else {
                int cur = dq.front();
                dq.pop_front();
                int nxt = dq.front();
                dq.pop_front();
                if (cur == -1) {
                    ans = ans + nxt;
                } else {
                    ans = ans - nxt;
                }
            }
        }
        if (ans == 24) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}