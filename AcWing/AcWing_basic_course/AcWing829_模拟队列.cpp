#include <bits/stdc++.h>
using namespace std;

int que[100010], front = 0, rear = 0;
int main(){
    cin.tie(0), cout.tie(0);
    int m;
    cin >> m;
    while(m--){
        string opt;
        int x;
        cin >> opt;
        if(opt == "push"){
            cin >> x;
            que[front++] = x;
        } else if(opt == "pop"){
            rear++;
        } else if(opt == "empty"){
            if(rear == front){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else{
            cout << que[rear] << endl;
        }
    }
    return 0;
}
