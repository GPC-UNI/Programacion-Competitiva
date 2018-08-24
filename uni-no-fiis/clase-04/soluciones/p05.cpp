/**
 * LINK DEL PROBLEMA:
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3084
 *
 * SOLUCIÓN:
 * Iteramos por todos los 1 en la representacion binaria de 'n' y con ello
 * vamos formando los números 'a' y 'b'
 *
 * COMPLEJIDAD:
 * O(log(n))
 *
 * DETALLES DE LA IMPLEMENTACIÓN:
 * n & -n = 2 ** (posición del 1 más a la derecha de 'n')
 */


#include <bits/stdc++.h>

using namespace std;

int n, a, b;

void print() {
    cout << a << ' ' << b << endl;
}

void solve() {
    a = b = 0;
    bool flag = true;
    while (n) {
        flag ? a |= n bitand -n : b |= n bitand -n;
        n = n bitand (n - 1);
        flag = !flag;
    }
}

int main() {
    while (cin >> n, n) {
        solve();
        print();
    }
    return (0);
}
