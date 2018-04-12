// Mas rato lo subo

#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

backtrack(int x, int y) {
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (isValid(nx, ny)) backtrack(nx, ny);
    }
}

int main() {
    return (0);
}
