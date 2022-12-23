#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int son[N][26], idx;
int cnt[N];
int n;

void insert(string str){
    int p = 0;
    for(int i = 0; str[i]; ++i){
        char ch = str[i] - 'a';
        if(!son[p][ch]) son[p][ch] = ++idx;
        p = son[p][ch];
    }
    cnt[p]++;
}

void query(string str){
    int p = 0;
    for(int i = 0; str[i]; ++i){
        char ch = str[i] - 'a';
        if(!son[p][ch]){
            cout << "0" << endl;
            return;
        }
        p = son[p][ch];
    }
    cout << cnt[p] << endl;
    return;
}

int main(){
    cin >> n;
    char opt;
    string str;
    while(n--){
        cin >> opt >> str;
        if(opt == 'I'){
            insert(str);
        } else{
            query(str);
        }
    }
    return 0;
}
