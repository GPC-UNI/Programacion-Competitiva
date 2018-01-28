/**
 * link : https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=36&mosmsg=Submission+received+with+ID+20682109
 * Problema:
 * Sea una sequencia S = {s1, s2, ..., sn, ...}
 * Te daran dos valores a, b
 * Debes dar como respuesta el mayor si [i = a, a + 1, ..., b]
 */

/**
 * Solucion:
 * Itera desde a hasta b, ve generando el elemento que necesitamos de la
 * secuencia y busca el mayor
 */

#include <bits/stdc++.h>

using namespace std;

int a, b;

int getValue(int num) {
    int ret = 1;
    while (num != 1) {
        num =  (num % 2 == 1) ? 3 * num + 1 : num / 2;
        ret++;
    }
    return ret;
}

int getAnswer(int a, int b) {
    int _max = 1;
    for (int it = a; it <= b; it++)
        _max = max(_max, getValue(it));
    return _max;
}

int main() {
    while (cin >> a >> b) cout << a << ' ' << b << ' ' << getAnswer(min(a, b), max(a, b)) << endl;
    return (0);
}