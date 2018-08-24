#include<bits/stdc++.h>

using namespace std;

string s;

int main(){
	int tc;
	cin >> tc;

	getline(cin, s);

	while(tc--){
		getline(cin, s);
		stack<char>pila;

		bool ok = true;
		for(int i=0; ok and i<s.size(); i++){
			if( pila.empty()  ){
				if( s[i]=='(' or s[i]=='[' ) pila.push(s[i]);
				else ok = false;
			}
			else{
				if(s[i]=='(' or s[i]=='[') pila.push(s[i]);
				else{
					char tope = pila.top();
					pila.pop();

					if( ( s[i]==')' and tope == '(' ) or ( s[i]==']' and tope == '[' )  ) continue;
					else ok = false;

				}
			}
		}

		if(ok and pila.empty()) puts("Yes");
		else puts("No");

	}

	return 0;
}
