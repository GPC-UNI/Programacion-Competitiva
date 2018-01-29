#include<bits/stdc++.h>

using namespace std;

string s;

int main(){

	//getline(cin, s);
	int x, n = 0, acum = 0;	

	s = "10 20 30 40 -2 -5 0";

	istringstream ss(s);

	while(ss >> x){
		acum += x;
		n++;
	}

	cout << "Se ingresaron " << n << " numeros" << endl;
	cout << "La suma es: " << acum << "." << endl;

	return 0;
}
