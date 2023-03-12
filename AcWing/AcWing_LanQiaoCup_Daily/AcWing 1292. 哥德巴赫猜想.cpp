#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int n;
int primes[N], cnt, st[N];

void get_primes(){
    st[0]=st[1]=1;
    for(int i=2;i<=N;++i){
        if(!st[i])  primes[cnt++]=i;
        for(int j=0;primes[j]<=N/i;++j){
            st[primes[j]*i]=1;
            if(i%primes[j]==0)  break;
        }
    }
}

int main(){
    get_primes();
    while(cin >> n, n){
        int l=0, r=cnt-1;
        while(l<r){
            int mid=l+r+1>> 1;
            if(primes[mid]>n)   r=mid-1;
            else                l=mid;
        }
        int i = l;
        while(1){
            if(!st[n-primes[i]]){
                cout << n << " = " << n-primes[i] << " + " << primes[i] << endl;
                break;
            }
            --i;
        }
        
    }
    return 0;
}