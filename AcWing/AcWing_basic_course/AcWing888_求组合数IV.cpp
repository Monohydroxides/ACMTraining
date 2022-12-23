#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int primes[N], cnt;
bool st[N];

int ex[N];

int get(int x, int p){
    int ext = 0;
    while(x){
        ext += x / p;
        x /= p;
    }
    return ext;
}

vector<int> mul(vector<int> a, int b){
    vector<int> res;
    int t = 0;
    for(int i = 0; i < a.size(); ++i){
        t += a[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }
    while(t){
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}

int main(){
    int a, b;
    cin >> a >> b;
    for(int i = 2; i <= N; ++i){
        if(!st[i])  primes[cnt++] = i;
        for(int j = 0; primes[j] <= N / i; ++j){
            st[i * primes[j]] = 1;
            if(i % primes[j] == 0)  break;
        }
    }
    for(int i = 0; i < cnt; ++i){
        ex[i] = get(a, primes[i]) - get(b, primes[i]) - get(a - b, primes[i]);
    }
    // for(int i = 0; i < cnt; ++i)    cout << primes[i] << " " << ex[i] << endl;
    vector<int> res;
    res.push_back(1);
    for(int i = 0; i < cnt; ++i){
        for(int j = 0; j < ex[i]; ++j){
            res = mul(res, primes[i]);
        }
        // for(int p = res.size() - 1; p >= 0; --p){
        //     cout << res[p];
        // }
    }
    for(int i = res.size() - 1; i >= 0; --i){
        cout << res[i];
    }
    cout << endl;
    return 0;
}
