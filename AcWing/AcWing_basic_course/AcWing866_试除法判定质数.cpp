#include <bits/stdc++.h>
using namespace std;
int n, a;
int tab[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
int main(){
    cin >> n;
    while(n--){
        cin >> a;
        int f = 0;
        if(a < 10 && !tab[a])  {cout << "No" << endl; continue;}
        else if(a < 10 && tab[a])   {cout << "Yes" << endl; continue;}
        if(a % 2 == 0){cout << "No" << endl; continue;}
        for(int i = 3; i <= a / i; i += 2){
            if(a % i == 0)  {f = 1, cout << "No" << endl;  break;}
        }
        if(!f)  cout << "Yes" << endl;
    }
    return 0;
}
