#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n;
PII a[N];

int main(){
    cin >> n;
    int ai, bi;
    for(int i = 1; i <= n; ++i){
        cin >> ai >> bi;
        a[i] = {bi, ai};
    }
    sort(a + 1, a + 1 + n);
    int res = 0, ed = -0x3f3f3f3f;
    for(int i = 1; i <= n; ++i){
        if(ed < a[i].second) ed = a[i].first, res ++;
    }
    cout << res << endl;
    return 0;
}
