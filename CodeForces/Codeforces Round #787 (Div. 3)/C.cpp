#include <bits/stdc++.h>
using namespace std;

int T;

void work(){
    char str[200010];
    cin >> str;
    int len=strlen(str);
    if(len==1){
        cout << 1 << endl;
        return;
    }
    int last1=-1, first0=-1;
    for(int i=len-1;i>=0;--i){
        if(str[i]=='1'){
            last1=i;
            break;
        }
    }
    for(int i=0;i<len;++i){
        if(str[i]=='0'){
            first0=i;
            break;
        }
    }
    if(last1!=-1 && first0!=-1){
        if(first0<last1){
            cout << 1 << endl;
        }else{
            cout << first0-last1+1 << endl;
        }
    }else{
        if(last1==-1 && first0!=-1){
            cout << first0+1 << endl;
        }else if(last1!=-1 && first0==-1){
            cout << len-last1 << endl;
        }else{
            cout << len << endl;
        }
    }
    return;
}

int main(){
    cin >> T;
    while(T--)  work();
    return 0;
}