#include <bits/stdc++.h>
using namespace std;

int T;

void work(){
    int n;
    cin >> n;
    if(n & 1){
        cout << -1 << endl;
    }else{
        cout << 0 << " " << n / 2 << " " << n / 2 << endl;
    }
    return;
}

int main(){
    cin >> T;
    while(T--)  work();
    return 0;
}