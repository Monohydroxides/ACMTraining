#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

int st, ed;
int n;
PII a[100010];

int main(){
    cin >> st >> ed;
    cin >> n;
    int q, p;
    for(int i = 1; i <= n; ++i){
        cin >> p >> q;
        a[i] = {p, q};
    }
    sort(a + 1, a + 1 + n);
    int res = 0;
    bool flag = 0;
    for(int i = 1; i <= n; ++i){
        int r = -0x3f3f3f3f;
        int j, tmp;
        for(j = i; j <= n; ++j){
            if(a[j].first <= st){
                r = max(r, a[j].second);
                tmp = j;
            } else {
                break;
            }
        }
        res ++;
        // cout << "r : " << r << endl;
        // cout << "j : " << j << endl;
        if(r < st)  {
            cout << -1 << endl;
            return 0;
        }
        if(r >= ed) {flag = 1; break;}
        i = tmp;
        st = r;
    }
    if(!flag)   {cout << -1 << endl; return 0;}
    cout << res << endl;
    return 0;
}
