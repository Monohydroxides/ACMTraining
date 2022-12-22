#include <bits/stdc++.h>
using namespace std;

int T;

char str[200010];

void work(){
    cin >> str;
    if(str[strlen(str) - 1] == 'A' || strlen(str) < 2){
        cout << "NO" << endl;
        return;
    }
    int cnt = 0, las = -1;
    for(int i = 0; i < strlen(str); ++i){
        if(str[i] == 'B'){
            while(i < strlen(str) && str[i] == 'B')    ++i;
            
            if(i - las < cnt){
                cout << "NO" << endl;
                return;
            }
            las = i;
        }else{
            cnt++;
        }
    }
    cout << "YES" << endl;
}

int main(){
    cin >> T;
    while(T--)  work();
    return 0;
}