#include <bits/stdc++.h>
using namespace std;
int n;
string opt;
int h[100010], hp[100010], ph[100010];
int cnt;
void h_swap(int a, int b){
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void up(int a){
    while(a / 2 && h[a] < h[a / 2]){
        h_swap(a, a / 2);
        a /= 2;
    }
}
void down(int a){
    int t = a;
    if(a * 2 <= cnt && h[a * 2] < h[t])    t = a * 2;
    if(a * 2 + 1 <= cnt && h[a * 2 + 1] < h[t])    t = a * 2 + 1;
    if(a != t){
        h_swap(a, t);
        down(t);
    }
}
int main(){
    int a, b, m = 0;
    cin >> n;
    while(n--){
        cin >> opt;
        if(opt == "I"){
            cin >> a;
            ++cnt, ++m;
            h[cnt] = a;
            ph[m] = cnt;
            hp[cnt] = m;
            up(cnt);
        } else if(opt == "PM")  cout << h[1] << endl;
        else if(opt == "DM"){
            h_swap(1, cnt);
            --cnt;
            down(1);
        } else if(opt == "D"){
            cin >> a;
            a = ph[a];
            h_swap(a, cnt);
            --cnt;
            up(a), down(a);
        } else {
            cin >> a >> b;
            a = ph[a];
            h[a] = b;
            up(a), down(a);
        }
    }
    return 0;
}
