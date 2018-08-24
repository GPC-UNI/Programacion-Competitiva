/**
 * LINK DEL PROBLEMA:
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2146
 *
 * SOLUCIÓN
 * Busquemos todas las posibles configuraciones
 *
 * COMPLEJIDAD:
 * O(N * log(N) * 2 ^ P)
 */

#include <bits/stdc++.h>

using namespace std;

int T, P, N, ans;
vector <int> number;

void print() {
    cout << ans << endl;
}

void solve() {
    for (int mask = 0; mask < (1 << P); mask++) {
        set <int> required;
        for (int i = 0; i < number.size(); i++) required.insert(mask bitand number[i]);
        if (required.size() == N) ans = min(ans, (int)__builtin_popcount(mask));
    }
}

void readCase() {
    cin >> P >> N;
    for (int i = 0; i < N; i++) {
        int num = 0;
        for (int j = 0, bit; j < P; j++) {
            cin >> bit;
            if (bit) num |= 1 << j;
        }
        number.push_back(num);
    }
}

void init() {
    number.clear();
    ans = INT_MAX;
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
