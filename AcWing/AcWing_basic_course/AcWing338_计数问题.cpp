#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int countbit(int x){
    int res = 0;
    while(x > 0){
        x /= 10;
        res++;
    }
    return res;
}

int countnumb(int size, int num){
    int bitnum = countbit(size), res = 0;
    for(int i = 1; i <= bitnum; ++i){
        int l = size / (int)pow(10, i), r = size % (int)pow(10, i - 1), p = size / (int)pow(10, i - 1) % 10;
        if(num) res += l * pow(10, i - 1);
        if(!num && l)    res += (l - 1) * pow(10, i - 1);
        if(p > num && (num || l))   res += pow(10, i - 1);
        if(p == num && (num || l))  res += r + 1;
    }
    return res;
}


void count(int a, int b){
    for(int i = 0; i < 10; ++i){
        cnt[i] = countnumb(b, i) - countnumb(a - 1, i);
    }
    return;
}

int main(){
    int a, b;
    cin >> a >> b;
    while(!(a == 0 && b == 0)){
        if(a > b)   swap(a, b);
        memset(cnt, 0, sizeof cnt);
        count(a, b);
        for(int i = 0; i < 10; ++i) cout << cnt[i] << " ";
        cout << endl;
        cin >> a >> b;
    }
    return 0;
}
