#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

vector<PII> a;

int n;

int main(){
    cin >> n;
    int p, b;
    for(int i = 1; i <= n; ++i){
        cin >> p >> b;
        a.push_back({b, p});
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    int ed = -0x3f3f3f3f;
    for(int i = 0; i < a.size(); ++i){
        if(ed < a[i].second){
            ed = a[i].first;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
