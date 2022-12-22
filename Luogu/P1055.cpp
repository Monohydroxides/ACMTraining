#include <bits/stdc++.h>
using namespace std;

int main(){
	char chr;
	char str[20];
	int cnt=0;
	while(scanf("%c", &chr)){
		if(chr!='-'){
			str[++cnt]=chr;
			if(cnt>=10)	break;
		}
	}
	int res=0;
	for(int i=1;i<=cnt;++i){
		if(i!=cnt){
			res=(res+i*(int)(str[i]-'0'))%11;
		}else{
			if((res%11!=10 && res%11==(int)(str[i]-'0')) || (res%11==10 && str[i]=='X')){
				cout << "Right" << endl;
			}else{
				cout << str[1] << '-' << str[2] << str[3] << str[4] << '-' << str[5] << str[6] << str[7] << str[8] << str[9] << '-';
				if(res%11==10)	cout << 'X' << endl;
				else			cout << res%11 << endl;
			}
		}
	}
	return 0;
}