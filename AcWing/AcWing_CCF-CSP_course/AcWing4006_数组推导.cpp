#include <bits/stdc++.h>
using namespace std;
int n;
int a[110];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int maxn = a[1], minn = a[1];
    for(int i = 2; i <= n; ++i){
        if(a[i] > a[i - 1]){
            maxn += a[i];
            minn += a[i];
        } else {
            maxn += a[i];
        }
    }
    cout << maxn << endl << minn << endl;
    return 0;
}
