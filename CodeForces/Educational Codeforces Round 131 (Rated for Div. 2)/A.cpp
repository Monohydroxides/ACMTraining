#include <bits/stdc++.h>
using namespace std;

void work(){
    int a[5];
    int cnt = 0;
    for(int i = 1; i <= 4; ++i){
        cin >> a[i];
        if(a[i])    cnt++;
    }
    if(cnt == 0){
        cout << 0 << endl;
    }else if(cnt == 1 || cnt == 2 || cnt == 3){
        cout << 1 << endl;
    }else if(cnt == 4){
        cout << 2 << endl;
    }
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}