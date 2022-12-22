#include <bits/stdc++.h>
using namespace std;


int T;

void work(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int res=0;
    if(x-a<0)   res=0;
    else        res=x-a;
    if(y-b>0)   res+=y-b;
    if(res<=c){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return;
}

int main(){
    cin >> T;
    while(T--)  work();
    return 0;
}
