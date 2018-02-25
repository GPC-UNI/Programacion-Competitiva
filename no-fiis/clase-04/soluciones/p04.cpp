/**
 * LINK DEL PROBLEMA:
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3682
 *
 * SOLUCIÓN:
 * Simulemos todo el proceso
 * Sea 'arr' un array de los 2 ** N jugadores que indica si el jugador se ha retiraro (false) o no (true)
 * Por ejemplo, para N = 3, tenemos
 * arr[0] arr[1] arr[2] arr[3] arr[4] arr[5] arr[6] arr[7]    [8 elementos]
 *     \   /          \   /        \    /       \    /
 *     arr'[0]        arr'[1]      arr'[2]      arr'[3]       [4 elementos]
 *         \           /              \          /
 *          arr''[0]                    arr''[1]              [2 elementos]
 *                  \                    /
 *                        arr''[0]                            [1 elemento ]
 * Entonces, para simular el proceso el array lo iteramos de 2 en 2
 * Y si de los dos elementos que estoy verificando, uno es falso, eso significa que estamos en un
 * w / o, asi que aumentamos un contador que será la respuesta y el elemento que agreguemos al nuevo
 * array sera verdadero si alguno de los elementos que estoy verificando lo es. Luego procedemos a hacer
 * lo mismo con el nuevo array formado, y continuamos con el proceso hasta que obtegamos un array de 1 elemento
 *
 * COMPLEJIDAD:
 * O(2 ^ (N + 1))
 *
 * DETALLES DE LA IMPLEMENTACIÓN:
 * var >>= 1 'es igual a' var /= 2 'es igual a' var = var / 2
 * bitor = | = OR OPERATION
 * xor = ^ = XOR OPERATION
 */

#include <bits/stdc++.h>

using namespace std;

const int N_PLAYERS = 1 << 10, OFFSET = 1;

int T, N, M, ans;
bool arr[N_PLAYERS + OFFSET];

void print() {
    cout << ans << endl;
}

void solve() {
    int limit = 1 << N;
    while (limit != 1) {
        for (int bit = 0; bit < limit; bit += 2) {
            bool bit_1 = arr[bit];
            bool bit_2 = arr[bit + 1];
            if (bit_1 xor bit_2) ans++;
            arr[bit >> 1] = bit_1 bitor bit_2;
        }
        limit >>= 1;
    }
}

void readCase() {
    cin >> N >> M;
    for (int player = 0; player < (1 << N); player++) arr[player] = true;
    for (int i = 0, player; i < M; i++) {
        cin >> player;
        arr[--player] = false;
    }
}

void init() {
    ans = 0;
}

int main() {
    cin >> T;
    while (T--) {
        init();
        readCase();
        solve();
        print();
    }
    return (0);
}
