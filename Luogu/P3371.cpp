#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
const int M = 500010;
int n, m, s;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
typedef pair<int, int> PII;

void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int s){
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, s});
	while(heap.size()){
		auto t = heap.top();
		heap.pop();
		st[t.second] = 1;
		for(int i = h[t.second]; i != -1; i = ne[i]){
			if(dist[e[i]] > w[i] + t.first){
				dist[e[i]] = w[i] + t.first;
				if(!st[e[i]])	heap.push({dist[e[i]], e[i]});	
			}
		}
	}
	for(int i = 1; i <= n; ++i)	if(dist[i] != 0x3f3f3f3f)	cout << dist[i] << " "; else	cout << 2147483647 << " ";
	return;
}


int main(){
	cin >> n >> m >> s;
	memset(h, -1, sizeof h);
	int a, b, c;
	for(int i = 1; i <= m;++i){
		cin >> a >> b >> c;
		add(a, b, c);
	}
	dijkstra(s);
	return 0;
}