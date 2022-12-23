#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;
    int x, res = 0;;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        if(i % 2)   res ^= x;
    }
    if(res) cout << "Yes" << endl;
    else    cout << "No"  << endl;
}
