/**
 * link : http://codeforces.com/problemset/problem/124/A
 * Problema:
 * Quieres determinar en cuantas posibles posiciones podrias estar
 */

/**
 * Solucion:
 * Prueba cada posicion y si es valida aumenta la respuesta en 1
 */

#include <bits/stdc++.h>

using namespace std;

int n, a, b, ans;

int main() {
    cin >> n >> a >> b;
    for (int pos = 1; pos <= n; pos++)
        if (pos - 1 <= b and a <= n - pos)
            ans++;
    cout << ans << endl;
    return (0);
}