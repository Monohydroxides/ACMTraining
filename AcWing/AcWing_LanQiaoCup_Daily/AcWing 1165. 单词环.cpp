#include <bits/stdc++.h>
using namespace std;

const int N = 26 * 26 + 10, M = 1e5 + 10;

int n, vid;
unordered_map<string, int> mp;

int head[N], nxt[M], to[M], eid;
double wt[M];

bool inq[N];
int jmp[N];
double dist[N];

void add (int a, int b, int c) {
	to[eid] = b, nxt[eid] = head[a], wt[eid] = c, head[a] = eid++;
}

bool spfa (double mid) {
	queue<int> qu;
	memset(jmp, 0, sizeof jmp);
	memset(inq, 0, sizeof inq);
	memset(dist, 0, sizeof dist);
	int count = 0;
	for (int i = 1; i <= 26 * 26; i++) {
		qu.push(i);
		inq[i] = 1; 
	}
	while (qu.size()) {
		int cur = qu.front();
		qu.pop();
		inq[cur] = 0;
		for (int i = head[cur]; ~i; i = nxt[i]) {
			int v = to[i];
			if (dist[v] < dist[cur] + wt[i] - mid) {
				dist[v] = dist[cur] + wt[i] - mid;
				jmp[v] = jmp[cur] + 1;
				if (jmp[v] >= N || ++count > 10000) {
					return true;
				}
				if (!inq[v]) {
					qu.push(v);
					inq[v] = 1;
				}
			}
		}
	}
	return false;
}

int get (string str) {
	return (str[0] - 'a') * 26 + (str[1] - 'a') + 1;
}

int main () {
	while (cin >> n, n) {
		eid = 0;
		memset(head, -1, sizeof head);
		for (int i = 1; i <= n; i++) {
			string str;
			cin >> str;
			if (str.size() <= 1) {
				continue;
			}	
			string st = str.substr(0, 2), ed = str.substr(str.size() - 2);
			int s = get(st), t = get(ed);
			add(s, t, str.size());
		}
		if (!spfa(0)) {
			cout << "No solution\n";
			continue;
		}
		double l = 0.0, r = 1000.0;
		while (fabs(r - l) > 0.005) {
			double mid = (l + r) / 2;
			if (spfa(mid)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		cout << fixed << setprecision(3) << r << "\n";
	}
	return 0;
}
