/**
 * LINK DEL PROBLEMA:
 * http://codeforces.com/problemset/problem/550/B
 *
 * SOLUCIÓN:
 * Básicamente tenemos un array 'c' con 'n' números y queremos saber
 * cuántos subconjuntos de 'c' podemos tomar tal que estos subconjuntos
 * tengan por lo menos 2 elementos, la suma de sus elementos sea >=
 * a 'x', su mínimo elemento sea >= a 'l' y su máximo elemento sea <= 'r'.
 * Ahora, si representamos esos subconjuntos como un string ('mask') de '1's y '0's
 * donde:
 * Si mask[i] = 1 -> Significa que ese conjunto contiene al elemento c[i]
 * Si mask[i] = 0 -> Significa que ese conjunto no continue al elemento c[i]
 * Entonces podemos generar todas las posibles configuraciones de 'mask' y 
 * tener un contador que aumente en caso generemos un subconjunto válido para
 * asi conseguir la respuesta.
 *
 * COMPLEJIDAD:
 * Notemos que cada elemento de 'mask' puede tomar 2 valores ('1' o '0')
 * Entonces, la cantidad de posibles configuraciones de 'mask' es:
 * 2 * 2 * ... * 2 ('n' veces) = 2 ^ n
 * De manera que, podemos resolver el problema en O(2 ^ n)
 *
 * DETALLES DE LA IMPLEMENTACIÓN:
 * (1 << n) = 2 ^ n
 * continue = pasar a la siguiente iteración
 * __builtin_popcount(n) = 'cantidad de '1's de 'n' representado en binario'
 * INT_MAX = máximo int que soporta c++
 * and = &&
 * bitand = &
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 15, OFFSET = 1;

int n, l, r, x, ans, c[MAX_N + OFFSET];

int main() {
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) < 2) continue;
        int min_diff = INT_MAX, max_diff = 0, sum = 0;
        for (int bit = 0; bit < n; bit++)
            if ((mask >> bit) bitand 1) {
                sum += c[bit];
                min_diff = min(min_diff, c[bit]);
                max_diff = max(max_diff, c[bit]);
            }
        if (l <= sum and sum <= r and (max_diff - min_diff) >= x) ans++;
    }
    cout << ans << endl;
    return (0);
}
