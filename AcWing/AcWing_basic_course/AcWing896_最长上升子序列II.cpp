#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], f[N], ptr = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    f[0] = -2e9;
    for(int i = 1; i <= n; ++i){
        if(a[i] > f[ptr])  f[++ptr] = a[i];
        else{
            int l = 0, r = ptr;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(f[mid] >= a[i])  r = mid - 1;
                else    l = mid;
            }
            ptr = max(ptr, r + 1);
            f[r + 1] = a[i];
        }
        // for(int j = 1; j <= ptr; ++j)   cout << f[j] << " ";
        // cout << endl;
    }
    cout << ptr << endl;
}

