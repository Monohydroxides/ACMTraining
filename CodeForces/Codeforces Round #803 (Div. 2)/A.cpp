#include <bits/stdc++.h>
using namespace std;

int T;

int a[110];

void work(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        int x = a[i];
        for(int j = 1; j < i; ++j){
            x ^= a[j];
        }
        for(int j = i + 1; j <= n; ++j){
            x ^= a[j];
        }
        if(x == 0){
            cout << a[i] << endl;
            return;
        }
    }
}

int main(){
    cin.tie(0);
    cin >> T;
    while(T--)  work();
    return 0;
}