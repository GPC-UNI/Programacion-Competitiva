/**
 * Usando Finding pattern or formula
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 110;

int n, ans[MAX_N][MAX_N];

int main() {
    cin >> n;
    for (int pos = 0; pos < n * n; pos++)
        ans[pos / n][pos % n] = pos & 1 ? n * n + 1 - ans[pos / n][pos % n - 1] : (pos / n) * n / 2 + (pos % n) / 2 + 1;
    for (int row = 0; row < n; row++)
        for (int col = 0; col < n; col++)
            printf(col == n - 1 ? "%d\n" : "%d ", ans[row][col]);
    return (0);
}