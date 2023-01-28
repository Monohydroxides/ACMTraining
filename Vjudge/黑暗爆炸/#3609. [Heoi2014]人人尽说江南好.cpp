#include <bits/stdc++.h>
using namespace std;

void work(){
	int n, m;
	cin >> n >> m;
	cout << (((m - 1) * (n / m) + max((n - (n / m) * m - 1), 0) & 1) ^ 1) << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--)	work();
	return 0;
}