#include<bits/stdc++.h>

using namespace std;

/*
Como tercer parametro de la funcion sort podemos agregar una funcion
que retorne un booleano, esta funcion sera usada para ordenar el array o vector,
el tipo de datos que reciben como parametro tiene que ser el mismo del array que
deseamos ordenar, unos ejemplos:
*/

bool mycomp(const int&x, const int&y){
	return x>y;
}

bool mycomp2(pair<int, int>x, pair<int, int>y){
	if( x.first != y.first ) return x.first < y.first;
	return x.second < y.second;
}

int a[] = {1, 4, 5, 7, 1, 5, 10};
vector<int>v(5);
pair<int, int>P[10];
int b[100];

int main(){

	/*Ordenar un array de forma decreciente
	por defecto al usar sort se odena de forma creciente
	*/
	sort(a, a+7, mycomp);

	for(int i=0; i<7; i++) cout << a[i] << " ";
	cout << endl;

	//Ordenar un vector
	
	v[0] = 10;
	v[1] = 2;
	v[2] = 4;
	v[3] = 6;
	v[4] = 5;

	sort(v.begin(), v.end(), mycomp);

	for(int i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;

	/*
	un pair guarda dos valores, los tipos de datos los tenemos que especificar cuando declaramos la variable
	Ejemplo pair<char, int>, pair<double, string>...
	Para acceder al primer elemnto usamos first: x.first
	Para acceder al segundo elemnto usamos second: x.second
	*/

	P[0].first = 4;
	P[0].second = 10;


	P[1].first = 2;
	P[1].second = 8;

	//Otra forma de crear un pair
	P[2] = make_pair(2, 10);

	for(int i=0; i<3; i++){
		cout << P[i].first << " " << P[i].second << endl;
	}

	cout << "Antes de ordenar" << endl;

	sort(P, P+3, mycomp2);	

	cout << "Despues de ordenar " << endl;

	for(int i=0; i<3; i++){
		cout << P[i].first << " " << P[i].second << endl;
	}

	return 0;
}
