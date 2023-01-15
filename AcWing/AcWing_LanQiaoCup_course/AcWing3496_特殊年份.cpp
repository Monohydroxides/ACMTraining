// copied from: https://www.acwing.com/solution/content/135650/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    int t=5,c=0;
    while(t--){
        cin>>st;
        if(st[0]==st[2]&&st[1]+1==st[3])c++;
    }
    cout<<c;
}