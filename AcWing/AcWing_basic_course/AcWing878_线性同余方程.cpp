#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;

int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    cin >> n;
    int a, b, p, x, y;
    while(n--){
        cin >> a >> b >> p;
        int d = exgcd(a, p, x, y);
        if(b % d != 0){
            cout << "impossible" << endl;
            continue;
        }
        cout << (long long)x * (b / d) % p << endl;
    }
    return 0;

}  
