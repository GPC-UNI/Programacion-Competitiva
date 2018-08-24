/**
	problem : http://codeforces.com/problemset/problem/555/D
	approach: binary search, math, simulation
	
	solution: para este problema el binary search sera un intermediario,
	vamos a simular el movimiento y tener cuidado con los bucles innecesarios
	(tal como que gire en un solo punto o que gire muchas veces por elementos),
	para probar la complejidad debemos ver que si voy del punto a para el punto b
	y luego a un punto c en medio de ellos, entonces el peor caso esta cuando
	c se encuentra en el punto medio del camino de a a b, esto ocurre ya que si
	la distancia es menor entonces el problema se reduce a un intervalo menor
	a la mitad, y si es mas que la mitad la cuerda piede mas de la mitad (en el 
	primer caso la cuerda hace giros "inutiles" sobre los mismos elementos
	en la peor de todas las situaciones)
	
	code: hay que mapear los indices de los elementos, para poder hacer busqueda
	binaria sobre ellos, luego tenga el cuenta la direccion del giro y los casos
	que gire muchas veces sobre el mismo par de puntos.
	
	complexity: O(n x log(n) + m x log(n) x log(l))
**/


#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int X[N], inv[N];
pair<int, int> B[N];
int n, m, a, l;	


int main(){

	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", X+i);
		B[i] = {X[i], i};
	}

	sort(B+1, B+n+1);
	for(int i = 1; i <= n; ++i)	
		inv[B[i].second] = i;


	while(m--){
		scanf("%d %d", &a, &l);
		
		a = inv[a];
		int prev = -1;
		bool ok = 1;
		int lo, hi;
		while(l){
			if(ok){
				lo = a; hi = n;
				while(lo < hi){
					int mid = lo + (hi-lo+1)/2;
					if(B[mid].first - B[a].first <= l) lo = mid;					
					else hi = mid-1;
				}

			}
			else{
				lo = 1; hi = a;
				while(lo < hi){
					int mid = lo + (hi-lo)/2;
					if(B[a].first - B[mid].first > l) lo = mid+1;
					else hi = mid;
				}
			}

			
			if(lo == prev){	
				if(lo == a) break;
				l %= 2*abs(B[a].first - B[lo].first);
				if(l == 0) break;
			}
			

			if(l >= abs(B[a].first - B[lo].first)){
				l -= abs(B[a].first - B[lo].first);
				prev = a;
				a = lo;
				ok ^= 1;
			}
		}

		printf("%d\n", B[a].second);
	}
	

	return 0;
}