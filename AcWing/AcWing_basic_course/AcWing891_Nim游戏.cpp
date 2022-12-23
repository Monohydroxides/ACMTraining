#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int res = 0;
    int a;
    while(n--){
        cin >> a;
        res ^= a;
    }
    if(res == 0)    puts("No");
    else    puts("Yes");
    return 0;
}
