#include <bits/stdc++.h>
using namespace std;
char optst[100010];
int numst[100010];
int opttop = -1, numtop = -1;
unordered_map<char, int> h{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };
int calc(int x, int y, char formula){
    switch(formula){
        case '+':{
            return x + y;
        }
        case '-':{
            return x - y;
        }
        case '*':{
            return x * y;
        }
        case '/':{
            return x / y;
        }
    }
}
int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        if('0' <= s[i] && s[i] <= '9'){
            int j = i + 1;
            int x = s[i] - '0';
            while(j < s.size() && s[j] <= '9' && s[j] >= '0'){
                x = x * 10 + s[j] - '0';
                ++j;
            }
            numst[++numtop] = x;
            i = j - 1;
        } else if(s[i] == '('){
            optst[++opttop] = '(';
        } else if(s[i] == ')'){
            while(optst[opttop] != '('){
                int y = numst[numtop--];
                int x = numst[numtop--];
                char formula = optst[opttop--];
                numst[++numtop] = calc(x, y, formula);
            }
            opttop--;
        } else {
            while(opttop != -1 && h[optst[opttop]] >= h[s[i]]){
                int y = numst[numtop--];
                int x = numst[numtop--];
                char formula = optst[opttop--];
                numst[++numtop] = calc(x, y, formula);
            }
            optst[++opttop] = s[i];
        }
    }
    while(opttop != -1){
        int y = numst[numtop--];
        int x = numst[numtop--];
        char formula = optst[opttop--];
        numst[++numtop] = calc(x, y, formula);
    }
    cout << numst[numtop] << endl;
    return 0;
}
