#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    pair<int, int> loc[4];
    for (int i = 1; i <= 3; ++i) {
        cin >> loc[i].first >> loc[i].second;
    }
    int edx, edy;
    cin >> edx >> edy;
    sort(loc + 1, loc + 1 + 3);
    int type = 0;
    if (loc[1].first < loc[2].first) {
        if (loc[1].second + 1 == loc[3].second) {
            type = 1;
        } else {
            type = 3;
        }
    } else {
        if (loc[1].second + 1 == loc[3].second) {
            type = 2;
        } else {
            type = 4;
        }
    }
    int holx, holy;
    if (type == 1) {
        holx = loc[1].first, holy = loc[1].second + 1;
    } else if (type == 2) {
        holx = loc[1].first + 1, holy = loc[1].second;
    } else if (type == 3) {
        holx = loc[1].first, holy = loc[1].second - 1;
    } else {
        holx = loc[1].first + 1, holy = loc[1].second + 1;
    }
    if (loc[1].first == 1 && loc[1].second == 1 && type == 4) {
        if (edx == 1 || edy == 1) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n";
        }
        return;
    }
    if (loc[2].first == 1 && loc[2].second == n && type == 2) {
        if (edx == 1 || edy == n) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n";
        }
        return;
    }
    if (loc[2].first == n && loc[2].second == 1 && type == 1) {
        if (edx == n || edy == 1) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n";
        }
        return;
    }
    if (loc[3].first == n && loc[3].second == n && type == 3) {
        if (edx == n || edy == n) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n";
        }
        return;
    }
    if (abs(edx - holx) % 2 == 0 && abs(edy - holy) % 2 == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}