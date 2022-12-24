#include <bits/stdc++.h>
using namespace std;

map<string, int> cnt[2];

vector<string> get (string str) {
    int sz = str.size();
    vector<string> ans;
    int i = 0, j = 0;
    while (i < sz) {
        j = i;
        while (j < sz && str[j] != '+') {
            j++;
        }
        ans.push_back(str.substr(i, j - i));
        i = j + 1;
    }
    return ans;
}

map<string, int> get_brack (string str) {
    int sz = str.size();
    map<string, int> ans;
    int i = 0;
    while (i < sz) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            int j = i + 1;
            if (j < str.size() && str[j] >= 'a' && str[j] <= 'z') {
                int elem_cnt = 0;
                j += 1;
                while (j < str.size() && str[j] >= '0' && str[j] <= '9') {
                    elem_cnt = (elem_cnt * 10) + (str[j] - '0');
                    j++;
                }
                if (!elem_cnt) {
                    elem_cnt = 1;
                }
                ans[str.substr(i, 2)] += elem_cnt;
                i = j;
            } else if (j < str.size() && str[j] >= '0' && str[j] <= '9') {
                int elem_cnt = 0;
                while (j < str.size() && str[j] >= '0' && str[j] <= '9') {
                    elem_cnt = (elem_cnt * 10) + (str[j] - '0');
                    j++;
                }
                if (!elem_cnt) {
                    elem_cnt = 1;
                }
                ans[str.substr(i, 1)] += elem_cnt;
                i = j;
            } else {
                string elem = str.substr(i, 1);
                ans[str.substr(i, 1)] += 1;
                i = j;
            }
        } else if (str[i] == '(') {
            int brack_cnt = 1;
            int j = i + 1;
            while (j < str.size() && brack_cnt != 0) {
                if (str[j] == '(') {
                    brack_cnt += 1;
                } else if (str[j] == ')') {
                    brack_cnt -= 1;
                }
                j += 1;
            }
            map<string, int> brack_elem_cnt = get_brack(str.substr(i + 1, j - i - 2));
            int brack_elem_times = 0;
            int k = j;
            while (k < sz && str[k] >= '0' && str[k] <= '9') {
                brack_elem_times = (brack_elem_times * 10) + (str[k] - '0');
                k++;
            }
            if (!brack_elem_times) {
                brack_elem_times = 1;
            }
            for (auto [p, v]: brack_elem_cnt) {
                ans[p] += v * brack_elem_times;
            }
            i = k;
        }
    } 
    return ans;
}

void count (vector<string> mol, int idx) {
    for (string str: mol) {
        int i = 0;
        int pref_cnt = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            pref_cnt = (pref_cnt * 10) + (str[i] - '0');
            i++;
        }
        if (!pref_cnt) {
            pref_cnt = 1;
        }
        while (i < str.size()) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                int j = i + 1;
                if (j < str.size() && str[j] >= 'a' && str[j] <= 'z') {
                    int elem_cnt = 0;
                    j += 1;
                    while (j < str.size() && str[j] >= '0' && str[j] <= '9') {
                        elem_cnt = (elem_cnt * 10) + (str[j] - '0');
                        j++;
                    }
                    if (!elem_cnt) {
                        elem_cnt = 1;
                    }
                    cnt[idx][str.substr(i, 2)] += elem_cnt * pref_cnt;
                    i = j;
                } else if (j < str.size() && str[j] >= '0' && str[j] <= '9') {
                    int elem_cnt = 0;
                    while (j < str.size() && str[j] >= '0' && str[j] <= '9') {
                        elem_cnt = (elem_cnt * 10) + (str[j] - '0');
                        j++;
                    }
                    if (!elem_cnt) {
                        elem_cnt = 1;
                    }
                    cnt[idx][str.substr(i, 1)] += elem_cnt * pref_cnt;
                    i = j;
                } else {
                    string elem = str.substr(i, 1);
                    cnt[idx][str.substr(i, 1)] += pref_cnt;
                    i = j;
                }
            } else if (str[i] == '(') {
                int brack_cnt = 1;
                int j = i + 1;
                while (j < str.size() && brack_cnt != 0) {
                    if (str[j] == '(') {
                        brack_cnt += 1;
                    } else if (str[j] == ')') {
                        brack_cnt -= 1;
                    }
                    j += 1;
                }
                map<string, int> brack_elem_cnt = get_brack(str.substr(i + 1, j - i - 2));
                int brack_elem_times = 0;
                int k = j;
                while (k < str.size() && str[k] >= '0' && str[k] <= '9') {
                    brack_elem_times = (brack_elem_times * 10) + (str[k] - '0');
                    k++;
                }
                if (!brack_elem_times) {
                    brack_elem_times = 1;
                }
                for (auto [p, v]: brack_elem_cnt) {
                    cnt[idx][p] += v * brack_elem_times * pref_cnt;
                }
                i = k;
            }
        }
    }
}

void work () {
    string func;
    cin >> func;
    string lhs, rhs;
    int i = 0;
    while (i < func.size() && func[i] != '=') {
        i++;
    }
    lhs = func.substr(0, i), rhs = func.substr(i + 1, func.size() - i);
    vector<string> l = get(lhs), r = get(rhs);
    cnt[0].clear(), cnt[1].clear();
    count(l, 0);
    count(r, 1);
    int flg = 1;
    for (auto [p, v]: cnt[0]) {
        if (v != cnt[1][p]) {
            flg = 0;
            break;
        }
    }
    for (auto [p, v]: cnt[1]) {
        if (v != cnt[0][p]) {
            flg = 0;
            break;
        }
    }
    cout << (flg == 1? "Y\n": "N\n");
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}