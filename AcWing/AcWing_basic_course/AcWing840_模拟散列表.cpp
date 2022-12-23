#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

int e[N], h[N], ne[N], idx;

void insert(int x){
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx++;
}

bool find(int x){
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i]){
        if(e[i] == x)   return true;
    }
    return false;
}

int main(){
    memset(h, -1, sizeof(h));
    int n, x;
    string opt;
    cin >> n;
    while(n--){
        cin >> opt >> x;
        if(opt == "I")  insert(x);
        else{
            if(find(x)) cout << "Yes" << endl;
            else    cout << "No" << endl;
        }
    }
    return 0;
}
