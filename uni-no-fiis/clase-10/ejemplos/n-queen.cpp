#include <bits/stdc++.h>

using namespace std;

const int N_ROWS = 8, N_COLS = 8;
const char QUEEN = 'Q', EMPTY = '.';

int ans;
char grid[N_ROWS + 1][N_COLS + 1];

bool valid(int row, int col) {
    for (int r = 0; r < N_ROWS; r++)
        for (int c = 0; c < N_COLS; c++)
            if ((r == row or c == col or abs(row - r) == abs(col - c)) and grid[r][c] == QUEEN)
                return false;
    return true;
}

void backtrack(int col = 0) {
    if (col == N_COLS) {
        printf("Configuración #: %2d\n", ++ans);
        for (int r = 0; r < N_ROWS; r++)
            for (int c = 0; c < N_COLS; c++)
                printf(c == N_COLS - 1 ? "%c\n" : "%c", grid[r][c]);
        puts("");
        return;
    }
    for (int row = 0; row < N_ROWS; row++) {
        if (valid(row, col)) {
            grid[row][col] = QUEEN;
            backtrack(col + 1);
            grid[row][col] = EMPTY;
        }
    }
}

int main() {
    memset(grid, EMPTY, sizeof grid);
    backtrack();
    return (0);
}
