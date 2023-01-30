#include <bits/stdc++.h>
using namespace std;

int n;

long long c(int a, int b){
    long long res = 1;
    for(int i = 1; i <= b; ++i){
        res *= (a - i + 1);
        res /= i;
    }
    return res;
}

int main(){
    cin >> n;
    cout << c(2 * n, n) / (n + 1)<< endl;
    return 0;
}