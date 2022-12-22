#include <bits/stdc++.h>
using namespace std;

void work(){
    int n;
    cin >> n;
    int b[200010];
    map<int, int> a;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        while(!(x & 1)) x /= 2;
        a[x]++;
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; ++i){
        while(!a[b[i]]){
            b[i] /= 2;
            if(!b[i]){
                cout << "NO" << endl;
                return;
            }
        } 
        a[b[i]] --;
    }
    cout << "YES" << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}