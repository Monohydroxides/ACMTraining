#include <bits/stdc++.h>
using namespace std;

int n;
int d[]={0,10,20,50,100};
int f[1010];

int main(){
    cin >> n;
    f[0]=1;
    for(int i=1;i<=4;++i){
        for(int j=d[i];j<=n;++j){
            f[j]+=f[j-d[i]];
        }
    }
    cout << f[n] << endl;
    return 0;
}
