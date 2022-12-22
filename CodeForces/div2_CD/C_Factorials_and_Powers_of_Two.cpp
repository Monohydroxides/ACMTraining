#include <bits/stdc++.h>
using namespace std;

int T;

long long num[30], cnt;

void init(){
    num[++cnt]=1;
    for(int i=2;i<100;++i){
        if(num[cnt]*i>1e12) break;  
        num[cnt+1]=num[cnt]*i;
        cnt++;
    }
}

int bitcnt(long long a){
    int res=0;
    while(a){
        res++;
        a-=(a&(-a));
    }
    return res;
}

void work(){
    long long n;
    cin >> n;
    int res=INT_MAX;
    for(int i=0;i<(1<<cnt);++i){
        long long tmp=n;
        for(int j=0;j<cnt;++j){
            if((1<<j)&i){
                tmp-=num[j+1];
                if(tmp<0)   break;
            }
        }
        if(tmp<0)   continue;
        res=min(res, bitcnt(i)+bitcnt(tmp));
    }
    cout << res << endl;
    return;
}

int main(){
    cin.tie(0);
    init();
    cin >> T;
    while(T--)  work();
    return 0;
}