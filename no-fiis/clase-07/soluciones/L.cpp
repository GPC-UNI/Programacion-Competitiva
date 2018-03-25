/**
	problem : http://codeforces.com/contest/549/problem/H
	approach: binary search, math
	
	solution: como queremos hallar el minimo podemos hacer nuestro
	predicado p(x) : x es mayor o igual al minimo, aqui ocurre algo interesante
	sucede que si abs(a - b) <= x con b la mejor matriz posible, entonces
	b[i][j] pertenece al rango [x - a, x + a], ahora como ademas
	se debe cumplir que la matriz b tenga determinante igual a 0, entonces
	se cumple b[0][0] x b[1][1] == b[0][1] x b[1][0] pero como solo
	sabemos que b[i][j] esta en un rango, y ademas sabemos que el producto
	de dos rangos sigue siendo un rango, basta saber que el preoducto
	de los rango de b[0][0] y b[1][1] se intersecta con el producto de
	los rango de b[0][1] y b[1][0].
	
	code: si tengo x que pertenece a [m, n] e y que pertenece a [p, q],
	entonces x.y pertenece al rango [min(min(m.p, m.q), min(n.p, n.q)), 
	max(max(m.p, m.q), max(n.p, n.q))].
	
	complexity: O(log(1e10))
**/


#include <bits/stdc++.h>
using namespace std;

typedef pair<long double, long double> segment;
int a[4];

segment multiply(segment x, segment y){
    
    long double  lx = min(min(x.first * y.first, x.second * y.first), 
                 min(x.first * y.second, x.second * y.second));
    long double rx = max(max(x.first * y.first, x.second * y.first), 
                 max(x.first * y.second, x.second * y.second));
    
    return segment(lx, rx);
}

bool intersect(segment a, segment b){
    return not (a.second  < b.first or b.second  < a.first);
}

bool p(long double x){
    return intersect(multiply(segment(a[0] - x, a[0] + x), segment(a[3] - x, a[3] + x)),
                    multiply(segment(a[1] - x, a[1] + x), segment(a[2] - x, a[2] + x)));
}


int main(){

    for(int i = 0; i < 4; ++i)
        cin >> a[i];
    
    long double lo = 0, hi = 1e10;
    for(int i = 0; i < 70; ++i){
        long double mid = lo + (hi - lo)/2;
        if(p(mid)) hi = mid;
        else lo = mid;
    }
    
    cout << fixed << setprecision(9) << lo << endl;
    
    return 0;
}