#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    string str;
    cin >> str;
    int ptr = 1;
    for(int i = 0; i < str.size() - 1; ++i){
        if(str[i] != '-'){
            a[ptr++] = (int)(str[i] - '0');
        }
    }
    int res = 0;
    for(int i = 1; i < ptr; ++i){
        res += i * a[i];
    }
    res %= 11;
    char ch;
    if(res == 10)   ch = 'X';
    else    ch = (char)('0' + res);
    if(ch == str[str.size() - 1])   cout << "Right" << endl;
    else{
        for(int i = 0; i < str.size() - 1; ++i){
            cout << str[i];
        }
        cout << ch << endl;
    }
    return 0;
}
