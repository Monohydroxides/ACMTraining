#include <bits/stdc++.h>
using namespace std;

vector<int> num;

vector<array<int, 3>> dfs (vector<int> cur, vector<array<int, 3>> opt) {
    if (cur.size() == 1) {
        if (cur[0] == 24) {
            return opt;
        } else {
            return vector<array<int, 3>>();
        }
    }
    for (int i = 0; i < cur.size(); i++) {
        for (int j = 0; j < cur.size(); j++) {
            if (i == j) continue;
            for (int op = 1; op <= 4; op++) {
                vector<int> tmp = cur;
                int lhs = tmp[i];
                int rhs = tmp[j];
                if (j < i) {
                    tmp.erase(tmp.begin() + j);
                    tmp.erase(tmp.begin() + i - 1);
                } else {
                    tmp.erase(tmp.begin() + i);
                    tmp.erase(tmp.begin() + j - 1);
                }
                if (op == 1) {
                    tmp.push_back(lhs + rhs);
                    vector<array<int, 3>> tmpopt = opt;
                    tmpopt.push_back({1, lhs, rhs});
                    auto ret = dfs(tmp, tmpopt);
                    if (ret.size()) {
                        return ret;
                    }
                } else if (op == 2) {
                    if (lhs <= rhs) continue;
                    tmp.push_back(lhs - rhs);
                    vector<array<int, 3>> tmpopt = opt;
                    tmpopt.push_back({2, lhs, rhs});
                    auto ret = dfs(tmp, tmpopt);
                    if (ret.size()) {
                        return ret;
                    }
                } else if (op == 3) {
                    tmp.push_back(lhs * rhs);
                    vector<array<int, 3>> tmpopt = opt;
                    tmpopt.push_back({3, lhs, rhs});
                    auto ret = dfs(tmp, tmpopt);
                    if (ret.size()) {
                        return ret;
                    }
                } else {
                    if ((lhs % rhs) || !rhs) continue;
                    tmp.push_back(lhs / rhs);
                    vector<array<int, 3>> tmpopt = opt;
                    tmpopt.push_back({4, lhs, rhs});
                    auto ret = dfs(tmp, tmpopt);
                    if (ret.size()) {
                        return ret;
                    }
                }
            }
        }
    }
    return vector<array<int, 3>>();
}

int main () {
    for (int i = 1; i <= 4; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    auto ret = dfs(num, vector<array<int, 3>>());
    if (ret.size()) {
        for (int i = 0; i < ret.size(); i++) {
            int lhs = max(ret[i][1], ret[i][2]);
            int rhs = min(ret[i][1], ret[i][2]);
            if (ret[i][0] == 1) {
                cout << lhs << "+" << rhs << "=" << lhs + rhs << '\n';
            } else if (ret[i][0] == 2) {
                cout << lhs << "-" << rhs << "=" << lhs - rhs << '\n';
            } else if (ret[i][0] == 3) {
                cout << lhs << "*" << rhs << "=" << lhs * rhs << '\n';
            } else {
                cout << lhs << "/" << rhs << "=" << lhs / rhs << '\n';
            }
        }
    } else {
        cout << "No answer!\n";
    }
    return 0;
}