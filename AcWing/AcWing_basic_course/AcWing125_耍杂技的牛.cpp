#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 5e4 + 10;

int n;
PII a[N];

int main(){
    cin >> n;
    int ai, bi;
    for(int i = 1; i <= n; ++i){
        cin >> ai >> bi;
        a[i] = {ai + bi, bi};
    }
    sort(a + 1, a + 1 + n);
    long long sum = a[1].first - a[1].second;
    long long res = -a[1].second;
    for(int i = 2; i <= n; ++i){
        // cout << "sum : " << sum << endl;
        // cout << "res : " << res << endl;
        res = max(res, sum - a[i].second);
        sum += a[i].first - a[i].second;
    }
    cout << res << endl;
    return 0;
}
