#include <bits/stdc++.h>
using namespace std;
 
bool st[10];
 
void check(int x){
    while(x){
        int p = x % 10;
        st[p] = 1;
        x /= 10;
    }
}
 
int main(){
    bool flag;
    for(int i = 40; i < 100; ++i){
        flag = true;
        memset(st, 0, sizeof st);
        check((int)pow(i, 2));
        check((int)pow(i, 3));
        for(int j = 0; j < 10; ++j){
            if(!st[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}