#include <bits/stdc++.h>
using namespace std;
int que[1000010], fnt = 0, rea = -1;
int a[1000010];
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i){
        if(rea <= fnt && i - k + 1 > que[rea])   rea++;
        while(rea <= fnt && a[que[fnt]] >= a[i])  fnt--;
        que[++fnt] = i;
        if(i >= k - 1)  cout << a[que[rea]] << " ";
    }
    cout << endl;
    fnt = 0, rea = -1;
    for(int i = 0; i < n; ++i){
        if(rea <= fnt && i - k + 1 > que[rea])  rea++;
        while(rea <= fnt && a[que[fnt]] <= a[i]) fnt--;
        que[++fnt] = i;
        if(i >= k - 1)  cout << a[que[rea]] << " ";
    }
    cout << endl;
    return 0;
}
