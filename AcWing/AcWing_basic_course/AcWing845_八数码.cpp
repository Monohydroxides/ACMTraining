#include <bits/stdc++.h>
using namespace std;

int fact[10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool vis[362900];

typedef struct point{
    char str[10];
    int step;
    int k;
}Point;

int hashn(char str[]){
    int res = 0;
    for(int i = 0; i < 9; ++i){
        int d = 0;
        for(int j = 0; j < i; ++j)  if(str[j] > str[i]) d++;
        res += d * fact[i];
    }
    return res;
}

bool strcmpare(char a[], char b[]){
    for(int i = 0; i < 9; ++i)  if(a[i] != b[i])    return false;
    return true;
}

void strcopy(char a[], char b[]){
    for(int i = 0; i < 9; ++i)  a[i] = b[i];
    a[9] = '\0';
}

int bfs(Point n){
    vis[hashn(n.str)] = 1;
    queue<Point> q;
    q.push(n);
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        // cout << now.str << endl;
        if(strcmpare(now.str, "12345678x"))   return now.step;
        int x = now.k / 3, y = now.k % 3;
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx > 2 || ny < 0 || ny > 2)    continue;
            char str[10];
            strcopy(str, now.str);
            str[now.k] = now.str[nx * 3 + ny];
            str[nx * 3 + ny] = 'x';
            if(!vis[hashn(str)]){
                vis[hashn(str)] = 1;
                Point ne;
                strcopy(ne.str, str), ne.step = now.step + 1, ne.k = nx * 3 + ny;
                q.push(ne);
            }
        }
    }
    return -1;
}


int main(){
    char ch;
    char str[10];

    fact[0] = 1;
    for(int i = 1; i <= 9; ++i) fact[i] = fact[i - 1] * i;

    int k;
    for(int i = 0; i < 9; ++i){
        cin >> ch;
        if(ch == 'x')   str[i] = 'x', k = i;
        else if('1' <= ch && ch <= '8') str[i] = ch;
    }

    Point st;
    strcopy(st.str, str);
    st.step = 0, st.k = k;
    cout << bfs(st) << endl;
    return 0;
}
