#include <bits/stdc++.h>
using namespace std;

void work(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i < n; ++i) {
        int r = i;
        while (r < n && a[r] == a[i]) r++;
        if (a[i] < a[i - 1] && a[i] < a[r]) {
            cout << "NO\n";
            return;
        }
        i = r - 1;
    } 
    cout << "YES\n";
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}