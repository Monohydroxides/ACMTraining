#include <bits/stdc++.h>
using namespace std;
 
bool check(int x){
    while(x){
        if(x % 10 == 4) return false;
        x /= 10;
    }
    return true;
}
 
int main(){
    int res = 0;
    for(int i = 10000; i <= 99999; ++i) if(check(i))    res++;
    cout << res << endl;
    return 0;
}