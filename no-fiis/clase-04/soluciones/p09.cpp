/**
 * LINK DEL PROBLEMA:
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2746
 *
 * SOLUCIÓN:
 * Iteramos por todas las posibles columnas en las que podriamos poner las
 * piezaz, por cada configuracion elegida, eliminamos todas las piezas en 
 * esa columna y luego chqueamos la cantidad de filas en las que aun quedan
 * piezas, si esta es menor o igual a la cantidad de piezas de la configuracion
 * que estamos iteracion, significa que podemos organizar esa configuracion
 * de tal manera que todas las piezas seas atacadas. Entonces, actualizamos
 * la respuesta de ser necesario
 *
 * COMPLEJIDAD:
 * O(2 ^ N * N * N) con N = 15
 */

#include <bits/stdc++.h>

using namespace std;

const int N_ROWS = 15, N_COLS = 15, OFFSET = 2;
const char EMPTY = '.', ENEMY = '#';

int ans;
string grid[N_ROWS + OFFSET], tmp[N_ROWS + OFFSET];

void print() {
    cout << ans << endl;
}

int process(int cols_used) {
    copy(grid, grid + N_ROWS, tmp);
    for (int col = 0; col < N_COLS; col++)
        if ((cols_used >> col) bitand 1) {
            for (int row = 0; row < N_ROWS; row++)
                tmp[row][col] = EMPTY;
        }
    int remaining = 0;
    for (int row = 0; row < N_ROWS; row++) {
        for (int col = 0; col < N_COLS; col++)
            if (tmp[row][col] == ENEMY) {
                remaining++;
                break;
            }
    }
    if (__builtin_popcount(cols_used) >= remaining) return __builtin_popcount(cols_used);
    return INT_MAX;
}

void solve() {
    for (int mask = 0; mask < (1 << N_COLS); mask++)
        ans = min(ans, process(mask));
}

bool readGrid() {
    cin >> grid[0];
    if (grid[0][0] == 'E') return false;
    for (int row = 1; row < N_ROWS; row++) cin >> grid[row];
    return true;
}

void init() {
    ans = INT_MAX;
}

int main() {
    while (readGrid()) {
        init();
        solve();
        print();
    }
    return (0);
}
