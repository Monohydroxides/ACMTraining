#include <bits/stdc++.h>
using namespace std;

int res = 0;
int r, c, k;
char mat[110][110];

int main(){
	cin >> r >> c >> k;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> mat[i][j];
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(mat[i][j] == '.'){
				if(k == 1){
					res++;
					continue;
				}
				int f = 0;
				for(int p = j; p < c; ++p){
					if(mat[i][p] != '.')	break;
					if(p - j + 1 == k){
						f = 1;
						break;
					}
				}
				if(f)	res++;
				f = 0;
				for(int p = i; p < r; ++p){
					if(mat[p][j] != '.')	break;
					if(p - i + 1 == k){
						f = 1;
						break;
					}
				}
				if(f)	res++;
			} 
		}
	}
	cout << res << endl;
	return 0;
}