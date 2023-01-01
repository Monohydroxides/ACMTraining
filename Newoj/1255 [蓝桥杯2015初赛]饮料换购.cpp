#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
    int n, res, emp;
    while(scanf("%d", &n) != EOF){
        res = n;
        emp = n;
        while(emp >= 3){
            res += emp / 3;
            int t = emp % 3;
            emp = emp / 3 + t;
        }
        cout << res << endl;
    }
    return 0;
}