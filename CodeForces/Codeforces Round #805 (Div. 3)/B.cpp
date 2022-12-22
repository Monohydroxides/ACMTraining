#include <bits/stdc++.h>
using namespace std;

void work(){
    string str;
    cin >> str;
    map<char, int> st;
    int cnt = 0, res = 0;
    for(int i = 0; i < str.size(); ++i){
        if(!st[str[i]]){
            if(cnt < 3){
                st[str[i]] = 1;
                cnt++;
            }else{
                res++;
                cnt = 1;
                st.clear();
                st[str[i]] = 1;
            }
        }
    }
    cout << res + 1 << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}