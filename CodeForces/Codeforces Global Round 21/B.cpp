#include <bits/stdc++.h>
using namespace std;

int T;

int a[100010];

void work(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int res = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i] == 0)   continue;
        int j = i;
        while(j <= n && a[j]) ++j;
        res++;
        i = j;
    }
    cout << min(res, 2) << endl;
}

int main(){
    cin.tie(0);
    cin >> T;
    while(T--)  work();
}