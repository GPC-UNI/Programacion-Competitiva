/**
 * link : https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=2091&mosmsg=Submission+received+with+ID+20682154
 * Problema:
 * Tiene n gaseosa
 * Si entregas 3 envases vacios te dan uno nuevo a cambio
 * Puedes prestarte un envase de un amigo si luego se lo devuelves
 * ¿ Cuantas gaseosas puedes tener como máximo ?
 */

/**
 * Solucion:
 * Ya tengo n gaseosas
 * De ellas puedo obtener n / 3 mas por la promocion y n % 3 no las usaria en la promocion
 * Puedo continuar aprovechandome de la promocion mientras tenga 3 gaseosas o mas
 * Si al final me sobran 2 gaseosas, puedo pedir a un amigo que me preste un envase
 * vacio, obtengo una gaseosa más con la promocion, la tomo y devuelvo el envase a mi amigo
 */

#include <bits/stdc++.h>

using namespace std;

int n;

int getAnwer(int num) {
    int ret = num;
    while (num >= 3) {
        ret += num / 3;
        num = num / 3 + num % 3;
    }
    if (num % 2 == 0) ret++;
    return ret;
}

int main() {
    while (cin >> n) cout << getAnwer(n) << endl;
    return (0);
}