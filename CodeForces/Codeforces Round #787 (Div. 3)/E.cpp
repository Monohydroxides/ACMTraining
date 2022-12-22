#include <bits/stdc++.h>
using namespace std;

int T;

void work(){
    int n, k;
    char str[200010];
    int flag[200];
    cin >> n >> k;
    cin >> str;
    for(int i=0;i<27;++i){
        flag['a'+i]='a'+i;
    }
    int las='a';
    for(int i=0;i<n;++i){
        if(str[i]=='a' || str[i]<=las) continue;
        if(k>=str[i]-las){
            k-=str[i]-las;
            las=max(las,(int)str[i]);
        }else{
            for(int j=(int)str[i]-k;j<=(int)str[i];++j){
                flag[j]=str[i]-k;
            }
            break;
        }
    }
    for(int i='a';i<=las;++i){
        flag[i]='a';
    }
    for(int i=0;i<n;++i){
        cout << (char)flag[(int)(str[i])];
    }
    cout << endl;
    return;
}

int main(){
    cin.tie(0);
    cin >> T;
    while(T--)  work();
    return 0;
}