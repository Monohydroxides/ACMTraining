#include <bits/stdc++.h>
using namespace std;
int st[100010], top = -1;
int main(){
    int n;
    cin >> n;
    int x;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        while(top > -1 && st[top] >= x){
            --top;
        }
        if(top == -1){
            cout << -1 << " ";
        } else {
            cout << st[top] << " ";
        }
        st[++top] = x;
    }
    return 0;
}
