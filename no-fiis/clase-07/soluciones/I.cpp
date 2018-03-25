/**

	*** REGIONAL PROBLEM ***

	problem : https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5217
	approach: ternary search, geometry
	
	solution: 
		
		Alguna vez hemos visto la ecuacion para hallar el area
		de un poligono, no es mas que sumar o restar las contribuciones
		de los triangulos que los forman desde un punto cualquiera, este
		punto puede ser el origen para mayor comodidad.

		Entonces si queremos hallar el area de un poligno de n
		puntos (x[i], y[i]) nuestra ecuacion seria:
		sum(x[i] * y[i+1] - y[i] * x[i+1], con 1 <= i < n) 
	        + x[n] * y[1] - y[n] * x[1], todo esto dividido entre
		dos pero, para nuetro problema eso no importa ya que no hallamos
		area sino volumen y la altura es 2, lo mas interesante
		de la ecuacion que hemos puesto que si yo quiero hallar
		el area des l a r, podria denotar ac[i] = ac[i-1] + x[i] * y[i+1]
		 - y[i] * x[i+1], entonces nuestra area de l a r queda
		expresada de la forma ac[r-1] - ac[l-1] + cross(r, l),
		donde la funcion cross denota el producto vectorial del
		punto r y l, en ese orden.

		ahora que ya sabemos hallar area en O(1), lo unico que queda es ver
		que propiedades tiene el problema, si denotamos f(a, b) como
		el area de f(a, b) a medida de que b se acerca a a el area disminuye,
		pero esto de que sirve, que sucede con el complemento de nuestra area,
		vemos que aumenta... entonces si denotamos g(b) a la funcion area(a, b)
		- complemento del area(a, b) vemos que en g(a) la funcion es negativa,
		y g(a + n - 1) que es justo -g(a), entonces esta funcion es positiva...
		pues esto es todo lo que necesitamos, quieres decir que hay una recta
		que hace a las dos areas iguales... pero espera! solo podemos usar las rectas 
		que pasan por a y otro punto, pues bien, aun asi debe haber un elemento
		lo bastante cerca a cero, tanto antes o despues de cero.

		Para hallar el que mas se le acerca tendriamos que buscar dos valores, quizas
		dos binarys ... o fijandonos en el que sigue, pero que pasa si ahora
		tomo h = abs(g) una nueva funcion, esta funcion que he creado a partir
		de una funcion binaria es convexa y alcanza el minimo justo en el
		punto que queremos (pruebe eso).
	
		  
	
		code:
		
	        entonces si a esta fijo podemos hallar un minimo y queremos el minimo para 
		todo a, pues tendremos que recorrer todo posible a y buscar ese minimo, tal
		vez no sea tan facil hallar punto medio por que todo es modular y eso, para
		ello podemos multiplicar el array x 2 y copiarlo, tal que asi si me paro en
		i, entonces el rango [i, i+n-1] representa mi array pero rotado i veces.
	
	complexity: O(n x log(n))
**/


#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5, OFFSET = 2;
int x[maxN + OFFSET], y[maxN + OFFSET];
long long total, ac[maxN];
int n; 

long long cross(int a, int b){
 	return x[a] * 1ll * y[b] - y[a] * 1ll * x[b];
}

long long area(int l, int r){
	return abs(ac[r-1] - ac[l-1] + cross(r, l));
}

long long f(int i, int mid){
	return abs(total - 2*area(i, mid));
}

long long df(int i, int mid){
 	return f(i, mid+1) - f(i, mid);
}

bool p(int i, int mid){
	return df(i, mid) < 0;
}


int main(){
	while(scanf("%d", &n) == 1){

		for(int i = 1; i <= n; ++i){
			scanf("%d %d", x+i, y+i);
			x[i+n] = x[i];
			y[i+n] = y[i];
		}

		for(int i = 1; i <= 2*n; ++i)
			ac[i] = ac[i-1] + cross(i, i+1);

		total = area(1, n);

       	        long long p1 = 0, p2 = 0;
		for(int i = 1; i <= n; ++i){
			int lo = i + 2, hi = i + n - 2;

			while(lo < hi){
				int mid = lo + (hi-lo)/2;
				if(p(i, mid)) lo = mid+1;
				else hi = mid;
			}
			
			if(max(p1, p2) < max(area(i, lo), total - area(i, lo)))
			    p1 = area(i, lo), p2 = total - area(i, lo);
		}
	
		if(p1 < p2) swap(p1, p2);		

		printf("%lld %lld\n", p1, p2);
	}	
	return 0;
}