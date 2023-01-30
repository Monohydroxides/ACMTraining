#include <bits/stdc++.h>
using namespace std;

void work(){
    long long n;
    cin >> n;
    if (!n) {
        cout << 0 << '\n';
        return;
    }
    long long res = 0;
    for(long long l = 1, r; l <= n; l = r + 1){
        r = n / (n / l);
        res += (n / l) * (r - l + 1);
    }
    cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}