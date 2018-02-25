/**
 * LINK DEL PROBLEMA:
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4763
 *
 * SOLUCIÓN:
 * Sea:
 * ans_1 = OR(a, a + 1, ..., b)
 * ans_2 = AND(a, a + 1, ..., b)
 * Si vemos a 'ans_1' y 'ans_2' como una máscara de bits, notemos:
 * ans_1[k] = 1 [Si a[k] = 1 o b[k] = 1 o algun c[k] = 1, donde a < c < b]
 * ans_1[k] = 0 [En caso contrario]
 * ans_2[k] = 1 [Si a[k] = 1 y b[k] = 1 y todo c[k] = 1, donde a < c < b]
 * ans_2[k] = 0 [En caso contrario]
 * Luego, notamos que:
 * Si a + 2 ** k < b:
 *      Existe algun c / c[k] = 1
 *      Existe algun c / c[k] = 0
 * Con esas observaciones podemos contruir 'ans_1' y 'ans_2'
 *
 * COMPLEJIDAD:
 * O(log(b))
 *
 * DETALLES DE LA IMPLEMENTACIÓN:
 * 1LL << k = (long long) 2 ** k
 */

#include <bits/stdc++.h>

using namespace std;

int tc, t;
long long a, b, ans_1, ans_2;

void solve() {
    ans_1 = ans_2 = 0;
    long long diff = b - a, k = 0;
    while (b) {
        long long pow2 = 1LL << k;
        if (b bitand 1 or a bitand 1 or diff > pow2) ans_1 |= pow2;
        if (b bitand 1 and a bitand 1 and diff < pow2) ans_2 |= pow2;
        a >>= 1, b >>= 1, k++;
    }
}

int main() {
    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        solve();
        cout << "Case " << ++t << ": " << ans_1 << ' ' << ans_2 << endl;
    }
    return (0);
}
