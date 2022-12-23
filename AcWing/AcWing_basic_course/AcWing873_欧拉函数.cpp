#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    int a;
    while(n--){
        cin >> a;
        long long res = a;
        for(int i = 2; i <= a / i; ++i){
            if(a % i == 0){
                while(a % i == 0){
                    a /= i;
                }
                res = res * (i - 1) / i;
            }
        }
        if(a != 1)  res = res * (a - 1) / a;   
        cout << res << endl;
    }
    return 0;
}
