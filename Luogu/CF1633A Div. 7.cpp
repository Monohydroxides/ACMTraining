#include<bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    while (n % 7) {
        n++;
        if (n % 10 == 0) {
            n-=10;
        }
    }
    cout << n << '\n';
}

int main(){
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}