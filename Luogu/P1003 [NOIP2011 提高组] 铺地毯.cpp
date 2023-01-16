#include <stdio.h>
struct mat {
	int datax,datay,lenx,leny;
};
int main () {
	int n,i,searchx,searchy,p,q,true_ = 0;
	scanf("%d",&n);
	struct mat data[n];
	for(i = 0; i < n; i++) {
		scanf("%d %d %d %d",&data[i].datax,&data[i].datay,&data[i].lenx,&data[i].leny);
	}
	scanf("%d %d",&searchx,&searchy);
	for(i = n-1; i >= 0; i--) {
		if(data[i].datax <= searchx && searchx <= data[i].datax + data[i].lenx &&data[i].datay <= searchy&&searchy <= data[i].datay +data[i].leny ) {
			printf("%d",i+1);
			true_ = 1;
			break;
		}
	}
	if(true_== 0) {
		printf("%d",-1);
	}
	return 0;
}