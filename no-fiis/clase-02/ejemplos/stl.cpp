#include<bits/stdc++.h>

using namespace std;

int main(){

	//VECTOR EN 1D
	
	/*vector de una dimension	
	En el primer parametro podemos especificar el tamaño
	En el segundo parametro podemos especificar un valor inicial para todos los elementos del vector
	*/
	vector<int>v1d(5, 0);

	//Eliminamos el ultimo elemento
	v1d.pop_back();

	//Agregamos elementos al final
	v1d.push_back(3);
	v1d.push_back(10);

	for(int i=0; i<v1d.size(); i++) cout << v1d[i] << " ";
	cout << endl;

	//Nos debe mostrar: 0 0 0 0 3 10

	//VECTOR EN MAS DIMENSIONES

	//Declaramos un vector de enteros de 3 filas y 4 columnas
	//con todos sus elementos inicializados en 1
	vector<vector<int> >v2d(3, vector<int>(4, 1));

	//Accdemos primero a la fila y despues a la columna
	v2d[1][2] = 9;

	//Modificamos algunas filas
	v2d[0].pop_back();
	v2d[2].push_back(5);

	cout << "2 dimensiones:" << endl;
	for(int i=0; i<v2d.size(); i++){
		for(int j=0; j<v2d[i].size(); j++) cout << v2d[i][j] << " ";
		cout << endl;
	}

	//SET

	//Declaramos un set s de enteros
	set<int>s;
	
	//Agregamos valores usando insert: O(log n)
	s.insert(10);
	s.insert(3);
	s.insert(5);
	s.insert(3);

	//Consultamos si algun valor esta dentro de s: O(log n)
	if(s.find(100)!=s.end()) puts("Si esta");
	else puts("No esta");

	//Recorremos y vemos que un elemnto solo puede existir una vez
	cout << "Set:" << endl;
	for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//MAP
	/*Nos permite crear una relacion clave->valor
	declaramos map<tipo1, tipo2>
	*/

	map<int, int>mapa;

	//Agregamos elementos
	mapa[1000000] = 6;
	mapa[10000] = 4;
	mapa[100] = 1;

	//Modificamos: O(log n)
	mapa[100] += 1;
	
	//Recorremos el map
	//Vemos que esta ordenado de acuerdo a las claves
	cout << "Map: " << endl;
	for(map<int, int>::iterator it = mapa.begin(); it!=mapa.end(); it++){
		cout << it->first << " -> " << it->second << endl;
	}

	return 0;
}
