/**
 * link : http://codeforces.com/problemset/problem/599/A
 * Problema:
 * Se quiere encontrar el minimo recorrido posible para salir de mi casa, visitar las 2 tiendas y regresa a cada
 */

/**
 * Solucion:
 * Son hay 4 posibles rutas que nos podrian dar el minimo recorrido
 * Calculamos las 4 y respondemos cual es la de menor valor
 */

#include <bits/stdc++.h>

using namespace std;

int d1, d2, d3;

int main() {
    cin >> d1 >> d2 >> d3;
    cout << min(d1 + d1 + d2 + d2, min(d1 + d3 + d2, min(d1 + d3 + d3 + d1, d2 + d3 + d3 + d2))) << endl;
    return (0);
}