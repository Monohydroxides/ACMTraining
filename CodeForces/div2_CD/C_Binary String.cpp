#include <bits/stdc++.h>
using namespace std;

int T;

void work(){
    char str[200010];
    scanf("%s", str+1);
    int len=strlen(str+1);
    int j=0;
    int cnt1=0,cnt0=0;
    for(int i=0;i<=len;++i){
        if(str[i]=='1') cnt1++;
    }
    int res=len;
    for(int i=1;i<=len;++i){
        while(cnt0<cnt1 && j<=len){
            ++j;
            if(str[j]=='1') cnt1--;
            else            cnt0++;
        }
        res=min(res,max(cnt1,cnt0));
        if(str[i]=='0') cnt0--;
        else            cnt1++;
    }
    cout << res << endl;
    return;
}

int main(){
    cin.tie(0);
    cin >> T;
    while(T--)  work();
    return 0;
}