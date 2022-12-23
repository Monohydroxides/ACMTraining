#include <bits/stdc++.h>
using namespace std;

string fmt;
int m;
map<char, int> argu;

int main () {
    cin >> fmt;
    cin >> m;
    
    int fmtsz = fmt.size();
    fmt = " " + fmt;
    for (int i = 1; i <= fmtsz; i++) {
        if (fmt[i] != ':') {
            if (i + 1 <= fmtsz && fmt[i + 1] == ':') {
                argu[fmt[i]] = 1;
            } else {
                argu[fmt[i]] = -1;
            }
        }
    }
    getchar();

    for (int Case = 1; Case <= m; Case++) {
        string str;
        getline(cin, str);

        stringstream ssin(str);

        vector<string> argus;

        while (ssin >> str) {
            argus.push_back(str);
        }

        map<char, string> ans;

        char las_argu = '0';
        for (int i = 1; i < argus.size(); i++) {
            // cout << argus[i] << "\n";
            if (argus[i][0] == '-' && argus[i][1] >= 'a' && argus[i][1] <= 'z') {
                if (las_argu == '0') {
                    las_argu = argus[i][1];
                } else {
                    if (argu[las_argu] == -1) {
                        ans[las_argu] = " ";
                        las_argu = argus[i][1]; 
                    } else if (argu[las_argu] == 1) {
                        ans[las_argu] = argus[i];
                        las_argu = '0';
                    } else {
                        break;
                    }
                }
            } else {
                if (argu[las_argu] == -1) {
                    ans[las_argu] = " ";
                    break;
                } else if (argu[las_argu] == 1) {
                    ans[las_argu] = argus[i];
                    las_argu = '0';
                } else {
                    break;
                }
            }
        }
        cout << "Case " << Case << ": ";
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (ans.count(ch)) {
                if (ans[ch] == " ") {
                    cout << "-" << ch << " ";
                } else {
                    cout << "-" << ch << " ";
                    cout << ans[ch] << " ";
                }
            }
        }
        cout << '\n';
    }
    return 0;
}