#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int T;
LL a[200010];

void work(){
    int n;
    cin >> n;
    int pos = 0, neg = 0, zro = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] > 0)    pos++;
        else if(a[i] < 0)    neg++;
        else if(a[i] == 0)   zro++;
    }
    if(pos >= 3 || neg >= 3){
        cout << "NO" << endl;
        return;
    }
    if(zro){
        if(pos >= 2 || neg >= 2){
            cout << "NO" << endl;
            return; 
        }
        if(pos && neg){
            sort(a + 1, a + 1 + n);
            if(a[1] + a[n] == 0){
                cout << "YES" << endl;
                return;
            }
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        return;
    }else{
        if(n == 4){
            LL s1 = a[1] + a[2] + a[3], s2 = a[1] + a[2] + a[4], s3 = a[2] + a[3] + a[4], s4 = a[1] + a[3] + a[4];
            int flg1 = 1, flg2 = 1, flg3 = 1, flg4 = 1;
            for(int i = 1;i <= n; ++i){
                if(a[i] == s1)  flg1 = 0;
                if(a[i] == s2)  flg2 = 0;
                if(a[i] == s3)  flg3 = 0;
                if(a[i] == s4)  flg4 = 0;
            }
            if(flg1 || flg2 || flg3 || flg4){
                cout << "NO" << endl;
                return;
            }
            cout << "YES" << endl;
            return;
        }else{
            LL s = a[1] + a[2] + a[3];
            for(int i = 1; i <= n; ++i){
                if(s == a[i]){
                    cout << "YES" << endl;
                    return;
                }
            }
            cout << "NO" << endl;
            return;
        }
    }
}

int main(){
    cin.tie(0);
    cin >> T;
    while(T--)  work();
    return 0;
}