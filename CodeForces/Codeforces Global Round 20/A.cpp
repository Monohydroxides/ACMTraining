#include <bits/stdc++.h>
using namespace std;

int T;

void work(){
    int n;
    cin >> n;
    int res = 0;
    int x;
    for(int i = 1; i <= n; ++i) cin >> x, res += x - 1;
    if(res & 1){
        cout << "errorgorn" << endl;
    }else{
        cout << "maomao90" << endl;
    }
}

int main(){
    cin >> T;
    while(T--)  work();
    return 0;
}