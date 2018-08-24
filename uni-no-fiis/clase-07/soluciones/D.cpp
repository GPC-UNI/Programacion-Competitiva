/**
	problem : http://codeforces.com/contest/578/problem/C
	approach: binary search, max array problem
	
	solution: 
		hint 1: lo que nos piden es la maxima suma en un 
		subarray de los elementos a[i] - x y los elementos 
		x - a[i] separadamente.

		hint 2: si nosotros escogemos un x, denotemos
		fl(x) = a la maxima suma en subarray de los elementos
		a[i] - x, y fr(x) a la maxima suma en subarray de los
		elementos x - a[i], ahora sea la funcion G, definida
		G(x) = fl(x) - fr(x), vemos que esta funcion es decreciente
		ya que es logico que al disminuir la resta, hay mas positivos
		para hacer una suma mas grande y al aumentar hay mas negativos
		tal que x - a[i] se vuelve mas negativo por tanto fr aumenta,
		entonces, ya que fl(x) decrece y fr(x) aumenta al aumentar x
		tenemos G(x) es decreciente.

		hint 3: existe y tal que G(y) = 0, basta con ver que G(-100000)
		es la suma de los elementos + 10000*n que es >= 0 y que G(100000)
		da 0 ya que no hay elemento mayor a 0. Por tanto tenemos que debe
		existir y tal que G(y) = 0.


        code: 
                Como existe y que da cero, basta con hacer busqueda binaria sobre
                fl(x) - fr(x) > 0 de donde queremos el primero que no cumpla.

		Sobre la implementacion debemos notar que si queremos hallar 
		la maxima suma desde nuestra posicion actual, esta es igual
		a la maxima suma anterior + el elemento actual o 0 ya que no
		hay maxima suma (por que si es negativa no nos importa por 
		eso se restringe los limites).

	
	complexity: O(n x log((max(a) - min(a))/eps))
**/


#include <bits/stdc++.h>
using namespace std;

const int N = 2e5, OFFSET = 2;
int n;
int a[N + OFFSET];
double ans;

void input(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
}

bool p(double x, bool ok = 0){

	double lans = 0, lans_ = 0;
	for(int i = 0; i < n; ++i){
		lans_ = max(lans_ + a[i] - x, 0.0d);	
		lans = max(lans, lans_);	
	}

	double rans = 0, rans_ = 0;
	for(int i = 0; i < n; ++i){
	 	rans_ = max(rans_ + x - a[i], 0.0d);
		rans = max(rans, rans_);
	}

    	if(ok) ans = max(lans, rans);

	return lans > rans;
}

void solve(){

	double lo = *min_element(a, a+n), hi = *max_element(a, a+n);
	for(int i = 0; i < 80; ++i){
		double mid = lo + (hi-lo)/2;
		if(p(mid)) lo = mid;
		else hi = mid;
	}

	printf("%.15Lf\n", (p(lo, 1), ans));
}



int main(){

	input();
	solve();

 	return 0;
}