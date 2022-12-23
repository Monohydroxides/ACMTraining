#include <bits/stdc++.h>
using namespace std;
int s[100010], top = -1;
void push(int x){
    s[++top] = x;
}
void pop(){
    --top;
}
bool empty(){
    return top == -1;
}
int query(){
    return s[top];
}
int main(){
    int m;
    cin >> m;
    while(m--){
        string opt;
        int x;
        cin >> opt;
        if(opt == "push"){
            cin >> x;
            push(x);
        } else if(opt == "pop"){
            pop();
        } else if(opt == "empty"){
            if(empty()){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else{
            cout << query() << endl;
        }
    }
    return 0;
}
