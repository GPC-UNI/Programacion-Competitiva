/**
 * link : http://codeforces.com/problemset/problem/334/A
 * Problema:
 * Tiene el conjunto A = {1, 2, ..., n * n}
 * Y debes crear n conjutos B de tamaño n tal que la union de todos esos conjuntos
 * sea A, que la interseccion entre cualquier de estos B sean nula y que la suma de sus elementos
 * sea la misma para cada B
 */

/**
 * Solucion:
 * sum(A) = n * n * (n * n + 1) / 2
 * Entonces
 * sum(B) = n * (n * n + 1) / 2 = (n / 2) * (n * n + 1)
 * Es decir, sea B = {b_1, b_2, ..., b_n}
 * estos deben ser tal que:
 * b_1 + b_n = n * n + 1
 * b_2 + b_(n - 1) = n * n + 1
 * b_3 + b_(n - 2) = n * n + 1
 * ... (Asi n / 2 ecuaciones)
 * Luego, podemos tomar para el primer B, b_1 = 1, b_n = n * n
 * Y contruir todos los conjuntos B a partir de ello
 */

#include <bits/stdc++.h>

using namespace std;

int n, id_1, id_2;

int main() {
    cin >> n;
    id_1 = 1, id_2 = n * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j += 2) cout << id_1++ << ' ' << id_2-- << ' ';
        cout << endl;
    }
    return (0);
}