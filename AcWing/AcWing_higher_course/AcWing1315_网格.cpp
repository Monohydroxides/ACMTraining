#include <bits/stdc++.h>
using namespace std;

int n, m;

int st[100010], primes[100010], cnt;
int sum[100010];

void get_primes(){
    for(int i = 2; i <= 100000; ++i){
        if(!st[i])  primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= 100000; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  break;
        }
    }
}

int get(int n, int p){
    int res = 0;
    while(n){
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> & a, int b){
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

vector<int> sub(vector<int> & a, vector<int> & b){
    vector<int> res;
    int t = 0;
    for(int i = 0; i < a.size(); ++i){
        int p = a[i] - t;
        if(i < b.size()){
            p -= b[i];
        }
        if(p < 0){
            t = 1;
            p += 10;
        }else{
            t = 0;
        }
        res.push_back(p);
    }
    while(res.back() == 0){
        res.pop_back();
    }
    return res;
}

vector<int> C(int a, int b){
    for(int i = 0; i < cnt; ++i){
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }
    vector<int> res;
    res.push_back(1);
    for(int i = 0; i < cnt; ++i){
        for(int j = 0; j < sum[i]; ++j){
            res = mul(res, primes[i]);
        }
    }
    return res;
}

int main(){
    cin >> n >> m;
    get_primes();
    vector<int> res1, res2, res3;
    res1 = C(n + m, m);
    res2 = C(n + m, m - 1);
    res3 = sub(res1, res2);
    reverse(res3.begin(), res3.end());
    for(int i = 0; i < res3.size(); ++i){
        cout << res3[i];
    }
    cout << endl;
    return 0;
}
