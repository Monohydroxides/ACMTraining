#include <bits/stdc++.h>
using namespace std;

void work(){
    int n;
    cin >> n;
    int k = 0;
    int res = 0;
    while(pow(10, k) <= n){
        res = n - pow(10, k);
        ++k;
    }
    cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}