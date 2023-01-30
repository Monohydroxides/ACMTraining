#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int l, n;
int a[N];

int main(){
	cin >> l >> n;
	for(int i=1;i<=n;++i)	cin >> a[i];
	sort(a+1, a+1+n);
	int maxn=0;
	if(n)	maxn=max(l+1-a[1], a[n]);
	int minn=0;
	for(int i=1;i<=n;++i){
		minn=max(minn, min(l+1-a[i], a[i]));
	}
	cout << minn << " " << maxn << endl;
	return 0;
}