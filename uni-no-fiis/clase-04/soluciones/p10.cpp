/**
 * LINK DEL PROBLEMA:
 * https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=217
 *
 * SOLUCIÓN:
 * Primero, notemos que si queremos hallar la mínima cantidad de movimientos
 * para tener la cuadrícula dada con todos los elementos iguales, entonces
 * no debemos mover una ficha más de una vez, pues es ese caso, ese movimiento solo 
 * revertiría el estado de esa posición.
 * Entonces, sabemos que si hay respuesta, esta consistirá en una serie de movimientos
 * en algunas fichas, esto es, si vemos la cuadrícula dada como un string
 * 'mask' de '1's y '0's donde si mask[i] = 1 significa mover la pieza grid[i / N_COLS][i % COLS]
 * Entonces, podemos iterar por todas las configuraciones de mask, simular los movimientos
 * y actualizar la respuesta si se cumplen las condiciones y tener una respuesta mejor
 *
 * COMPLEJIDAD:
 * O(k * 2 ^ 16) // donde con k = 5 * 16 podemos tener una cota superior
 *
 * DETALLES DE LA IMPLEMENTACIÓN:
 * ~num = Indica si 'num' != -1 (Representa -1 en binario y te darás cuenta)
 * not = !
 * dr[] y dc[] funcionan como 'vectores de dirección'(Lo explicaré en clase)
 * const type& var (Lo explicaré en clase)
 * inline (Lo explicaré en clase)
 * copy = ¿Qué crees que haga ._.? (http://www.cplusplus.com/reference/algorithm/copy/)
 */

#include <bits/stdc++.h>

using namespace std;

const int N_ROWS = 4, N_COLS = 4, N_DIR = 5, OFFSET = 1;

int ans;
string grid[N_ROWS + OFFSET], pib[N_ROWS + OFFSET];
int dr[] = {0, 0, -1, 0, 1};
int dc[] = {0, 1, 0, -1, 0};

inline void print() {
    ~ans ? cout << ans << endl : cout << "Impossible" << endl;
}

bool isAll(const char& ch) {
    for (int row = 0; row < N_ROWS; row++)
        for (int col = 0; col < N_COLS; col++)
            if (pib[row][col] != ch) return false;
    return true;
}

inline bool isValid(const int& r, const int& c) {
    return 0 <= r and 0 <= c and r < N_ROWS and c < N_COLS;
}

void markMoves(const int& pos) {
    int r = pos / N_COLS, c = pos % N_COLS;
    for (int d = 0; d < N_DIR; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (isValid(nr, nc)) pib[nr][nc] = (pib[nr][nc] == 'b') ? 'w' : 'b';
    }
}

void solve() {
    for (int mask = 0; mask < (1 << (N_ROWS * N_COLS)); mask++) {
        if (__builtin_popcount(mask) > ans and ~ans) continue;
        copy(grid, grid + N_ROWS, pib);
        for (int bit = 0; bit < (N_ROWS * N_COLS); bit++)
            if ((mask >> bit) bitand 1) markMoves(bit);
        if (isAll('b') or isAll('w')) ans = __builtin_popcount(mask);
    }
}

inline void init() {
    ans = -1;
}

bool readBoard() {
    for (int row = 0; row < N_ROWS; row++)
        if (not (cin >> grid[row])) return false;
    return true;
}

int main() {
    while (readBoard()) {
        init();
        solve();
        print();
    }
    return (0);
}
