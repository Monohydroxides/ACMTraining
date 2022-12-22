#include <bits/stdc++.h>
using namespace std;

void work(){
    string str;
    int p;
    cin >> str >> p;
    int cnt[30] = {0};
    int sum = 0;
    for(int i = 0; i < str.size(); ++i){
        cnt[str[i] - 'a' + 1]++;
        sum += str[i] - 'a' + 1;
    }
    for(int i = 26; i >= 1; --i){
        if(cnt[i]){
            if(sum <= p)    break;
            if(sum - cnt[i] * i > p){
                sum -= cnt[i] * i;
                cnt[i] = 0;
            }else{
                for(int j = 1; j <= cnt[i]; ++j){
                    if(sum - j * i <= p){
                        sum -= j * i;
                        cnt[i] -= j;
                        break;
                    }
                }
                break;
            }
        }
    }
    int rescnt[30] = {0};
    for(int i = 0; i < str.size(); ++i){
        if(rescnt[str[i] - 'a' + 1] + 1 <= cnt[str[i] - 'a' + 1]){
            cout << str[i];
            rescnt[str[i] - 'a' + 1]++;
        }
    }
    cout << endl;
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}