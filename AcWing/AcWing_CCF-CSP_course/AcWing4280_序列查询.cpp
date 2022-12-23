#include <bits/stdc++.h>
using namespace std;

int n, N;
int a[1000010];

int main(){
    cin >> n >> N;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int res = 0;
    int cnt = 1;
    for(int i = 2; i <= n; ++i){
        if(a[i] > N){
            res += cnt * (N - a[i - 1]);
            break;
        }
        res += cnt * (a[i] - a[i - 1]);
        cnt++;
    }
    if(N > a[n])    res += cnt * (N - a[n]);
    cout << res << endl;
    return 0;
}
