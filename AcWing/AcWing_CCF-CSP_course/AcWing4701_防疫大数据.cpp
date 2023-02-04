#include <bits/stdc++.h>
using namespace std;

int n, las;
vector<array<int, 3>> lasans, ans;
unordered_map<int, unordered_map<int, int>> rg;

int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int ri, mi;
        cin >> ri >> mi;
        if (i - 6 > las) {
            rg.erase(las);
            las++;
        }
        for (int j = 1; j <= ri; j++) {
            int pr;
            cin >> pr;
            for (int k = i; k <= i + 6; k++) {
                rg[k][pr] = 1;
            }
        }
        for (auto it : lasans) {
            if (it[2] >= i - 6 && rg.count(i) && rg[i].count(it[1])) {
                ans.push_back(it);
            }
        }
        for (int j = 1; j <= mi; j++) {
            int di, ui, rfi;
            cin >> di >> ui >> rfi;
            if (di >= i - 6) {
                int flg = 1;
                for (int k = di; k <= i; k++) {
                    if (!rg[k].count(rfi)) {
                        flg = 0;
                        break;
                    }
                }
                if (flg) {
                    ans.push_back({ui, rfi, di});
                }
            }
        }
        vector<int> out;
        cout << i << " ";
        for (auto it : ans) {
            out.push_back(it[0]);
        }
        sort(out.begin(), out.end());
        out.erase(unique(out.begin(), out.end()), out.end());
        for (auto it : out) {
            cout << it << " ";
        }
        cout << "\n";
        lasans = ans;
        ans.clear();
    }
    return 0;
}