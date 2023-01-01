#include <bits/stdc++.h>
using namespace std;

const int N=6500*2;

int t,c,ts,te;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
int st[N];

void add(int a, int b, int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({0,ts});
    dist[ts]=0;
    while(pq.size()){
        auto tmp=pq.top();
        pq.pop();
        if(st[tmp.second])  continue;
        st[tmp.second]=1;
        for(int j=h[tmp.second];~j;j=ne[j]){
            if(dist[e[j]]>dist[tmp.second]+w[j]){
                dist[e[j]]=dist[tmp.second]+w[j];
                pq.push({dist[e[j]],e[j]});
            }
        }
    }
    return dist[te];
}

int main(){
    memset(h,-1,sizeof h);
    cin >> t >> c >> ts >> te;
    for(int i=1;i<=c;++i){
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        add(aa,bb,cc),add(bb,aa,cc);
    }
    cout << dijkstra() << endl;
    return 0;
}
