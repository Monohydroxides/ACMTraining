#include <bits/stdc++.h>
using namespace std;

int n;
string str;
double f[2], g[2];

int main() {
	cin >> n;
	cin >> str;
	int t = 0;
	for(int i = 0; i < str.size(); ++i){
		if(str[i] == 'o'){
			f[t] = f[t ^ 1] + 2 * g[t ^ 1] + 1;
			g[t] = g[t ^ 1] + 1;
		}else if(str[i] == 'x'){
			f[t] = f[t ^ 1];
			g[t] = 0;
		}else{
			f[t] = f[t ^ 1] + g[t ^ 1] + 0.5;
			g[t] = 0.5 * g[t ^ 1] + 0.5;
		}
		t ^= 1;
	}
	printf("%.4lf\n", f[t ^ 1]);
	return 0;
}