#include <bits/stdc++.h>
using namespace std;

void work(){
    char res[1010];
    string str;
    cin >> str;
    int f = 0;
    for(int i = 0; i < str.size(); ++i){
        if((str[i] >= '0' && str[i] <= '9') || str[i] == '(' || str[i] == ')' || str[i] == ',' || str[i] == '-'){
            res[f++] = str[i];
        }
    }
    res[f] = '\0';
    cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}