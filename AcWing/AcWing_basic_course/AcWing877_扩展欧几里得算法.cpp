#include <bits/stdc++.h>
using namespace std;

int n;

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    cin >> n;
    int a, b, x, y;
    while(n--){
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << " " << y << endl;
    }
    return 0;
}
