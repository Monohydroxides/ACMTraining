#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    queue<int> res;
    for (int i = 1; i <= n; ++i) {
        res.push(i);
    }
    while (res.size() > 2) {
        int cur1, cur2;
        int fr = res.front(); res.pop();
        int se = res.front(); res.pop();
        int tr = res.front(); res.pop();
        cout << "? " << fr << " " << se << endl;
        cin >> cur1;
        cout << "? " << se << " " << tr << endl;
        cin >> cur2;
        if (cur1 == cur2) {
            res.push(fr), res.push(tr);
        } else if (cur1 < cur2) {
            res.push(se), res.push(tr);
        } else {
            res.push(se), res.push(fr);
        }
    }
    cout << "! " << res.front();
    res.pop();
    cout << " " << res.front() << endl;
    int ret;
    cin >> ret;
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}