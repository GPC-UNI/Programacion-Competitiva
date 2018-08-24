#include <bits/stdc++.h>

using namespace std;

const int R = 3, C = 3, MIN_POINTS_TO_TAKE = 3;

int grid[R + 1][C + 1], n_solution;
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

void printGrid() {
    printf("Solution #: %0.4d\n", ++n_solution);
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) cout << grid[r][c];
        cout << endl;
    }
    putchar('\n');
}

inline bool isValid(const int r, const int c) {
    return 0 <= r and r < R and 0 <= c and c < C and grid[r][c] == 0;
}

void backtrack(int r, int c, int num = 2) {
    if (num > MIN_POINTS_TO_TAKE) printGrid();
    for (int d = 0; d < 8; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (isValid(nr, nc)) {
            grid[nr][nc] = num;
            backtrack(nr, nc, num + 1);
            grid[nr][nc] = 0;
        }
    }
}

int main() {
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) {
            grid[r][c] = 1;
            backtrack(r, c);
            grid[r][c] = 0;
        }
    return (0);
}
