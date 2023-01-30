#include <bits/stdc++.h>
using namespace std;

int M, S, T;

int main(){
	cin >> M >> S >> T;
	int dist=0;
	for(int i=1;i<=T;++i){
		if(dist>=S){
			printf("Yes\n%d", i-1);
			return 0;
		}
		if(M>=10){
			M-=10;
			dist+=60;
		}else if(M+4*(T-i)<10 || dist+17>=S || (M<10 && dist+((13-M)/4+1)*17>=S)){
			dist+=17;
			continue;
		}else{
			M+=4;
		}
	}
	if(dist>=S)	printf("Yes\n%d", T);
	else		printf("No\n%d", dist);
    return 0;
}