#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main(){
	string str;
	cin >> str;
	stack<char> st;
	for(int i=0;i<str.size();++i){
		if(str[i]=='('){
			st.push('(');
		}else if(str[i]==')'){
			if(st.empty()){
				cout << "NO" << endl;
				return 0;
			}else{
				st.pop();
			}
		}
	}
	if(!st.empty()){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
	return 0;
}