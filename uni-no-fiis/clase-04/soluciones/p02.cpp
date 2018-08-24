/**
 * LINK DEL PROBLEMA:
 * http://codeforces.com/problemset/problem/467/B
 *
 * SOLUCIÓN:
 * Notemos que tenemos esto:
 * x[0] = mask[0]
 * x[1] = mask[1]
 * ...
 * x[m] = mask[m]
 * Y queremos saber la cantidad de x[i] (i < m) tal que la cantidad de '1's de x[i] y x[m] difieran en <= k
 * Entonces, notemos que podemos iterar por todos los 'i's < m y comprobar si se cumple tal condicion
 * para aumentar un contador que sería la respuesta
 * Dicha comprobacioón la podemos hacer iterando por los 'n' bits de cada 'mask'
 * como en el problema anterior, o podemos darnos cuenta de que:
 * Sea result = una máscara de 'n' bits, donde
 * result[j] = 1 si mask[i] y mask[m] difieren la cantidad de '1' en el bit 'j'
 * result[j] = 0 si mask[i] y mask[m] no difieren la cantidad de '1' en el bit 'j'
 * Entonces
 * Si mask[i][j] = 1 y mask[m][j] = 1 -> result[j] = 0
 * Si mask[i][j] = 1 y mask[m][j] = 0 -> result[j] = 1
 * Si mask[i][j] = 0 y mask[m][j] = 1 -> result[j] = 1
 * Si mask[i][j] = 0 y mask[m][j] = 0 -> result[k] = 0
 * Así, tenemos que: result[j] = mask[i][j] ^ mask[m][j]
 * Luego, result = mask[i] ^ mask[m]
 * Y si la cantidad de '1's en result es <= k, entonces la respuesta aumenta en 1
 *
 * COMPLEJIDAD:
 * O(m)
 *
 * DETALLES DE IMPLEMENTACIÓN:
 * xor = ^ = XOR OPERATION
 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 1000, OFFSET = 5;

int n, m, k, x[MAX_M + OFFSET], ans;

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i <= m; i++) cin >> x[i];
    for (int i = 0; i < m; i++) if (__builtin_popcount(x[i] xor x[m]) <= k) ans++;
    cout << ans << endl;
    return (0);
}
