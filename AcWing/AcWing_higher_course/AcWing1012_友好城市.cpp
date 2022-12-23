#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 5010;

int n;
int f[N];
PII a[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int aa, b;
        cin >> aa >> b;
        a[i] = {aa, b};
        f[i] = 1;
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            if(a[i].second > a[j].second)   f[i] = max(f[i], f[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; ++i) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}
