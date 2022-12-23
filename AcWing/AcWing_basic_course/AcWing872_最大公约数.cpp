#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}
int main(){
    int n;
    int a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a < b)   swap(a, b);
        cout << gcd(a, b) << endl;
    }
    return 0;
}
