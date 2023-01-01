#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        bool flag = false;
        for(int i = 1; i <= n / i; ++i){
            for(int j = i; j <= n / j; ++j){
                for(int k = j; k <= n / k; ++k){
                    if(i * i + j * j == n - k * k){
                        flag = true;
                        cout << i << " " << j << " " << k << endl;
                    }
                }
            }
        }
        if(!flag)   cout << "No Solution" << endl;
    }
}