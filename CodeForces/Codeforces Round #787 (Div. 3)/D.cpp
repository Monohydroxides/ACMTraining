#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int T;

int lnkcnt=1;

int h[N], e[N], ne[N], idx;
struct Link{
    vector<int> lst;
}link[N];

void add(int a, int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int node, int id){
    int cnt=0;
    link[id].lst.push_back(node);
    for(int i=h[node];~i;i=ne[i]){
        if(cnt==0){
            dfs(e[i], id);
            cnt=1;
        }else{
            lnkcnt++;
            dfs(e[i], lnkcnt);
        }
    }
}

void work(){
    int n;
    cin >> n;
    idx=0;
    lnkcnt=1;
    for(int i=0;i<=n;++i){
        h[i]=-1;
        link[i].lst.clear();
    }
    int rt=-1;
    for(int i=1;i<=n;++i){
        int x;
        cin >> x;
        if(x==i){
            rt=x;
            continue;
        }
        add(x,i);
    }
    // for(int i=1;i<=n;++i){
    //     for(int j=h[i];~j;j=ne[j]){
    //         cout << e[j] << " ";
    //     }
    //     cout << endl;
    // }
    dfs(rt,lnkcnt);
    cout << lnkcnt << endl;
    for(int i=1;i<=lnkcnt;++i){
        cout << link[i].lst.size() << endl;
        for(int j=0;j<link[i].lst.size();++j){
            cout << link[i].lst[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

int main(){
    cin >> T;
    while(T--)  work();
    return 0;
}