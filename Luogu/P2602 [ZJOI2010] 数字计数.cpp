#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL cnt[10];

int countbit(LL x){
    int res = 0;
    while(x > 0){
        x /= 10;
        res++;
    }
    return res;
}

LL countnumb(LL size, int num){
    int bitnum = countbit(size);
    LL res = 0;
    for(int i = 1; i <= bitnum; ++i){
        LL l = size / (LL)pow(10, i), r = size % (LL)pow(10, i - 1), p = size / (LL)pow(10, i - 1) % 10;
        if(num) res += l * pow(10, i - 1);
        if(!num && l)    res += (l - 1) * pow(10, i - 1);
        if(p > num && (num || l))   res += pow(10, i - 1);
        if(p == num && (num || l))  res += r + 1;
    }
    return res;
}


void count(LL a, LL b){
    for(int i = 0; i < 10; ++i){
        cnt[i] = countnumb(b, i) - countnumb(a - 1, i);
    }
    return;
}

int main(){
    LL a, b;
    cin >> a >> b;
    count(a, b);
    for(int i = 0; i < 10; ++i) cout << cnt[i] << " ";
    cout << endl;
    return 0;
}