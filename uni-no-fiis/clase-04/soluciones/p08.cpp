/**
 * LINK DEL PROBLEMA:
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3488
 * 
 * SOLUCIÓN:
 * Probamos todas las posibles soluciones recorriendo usando máscara de bits
 * Y, de ser necesario, vamos actualizando la respuesta en cada iteracion
 *
 * COMPLEJIDAD:
 * O((N + P) * 2 ^ N) [En realidad es menos, pero esta cota esta cerca]
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20, OFFSET = 2;

int T, N, M, P, service[MAX_N + OFFSET], ans_1;
vector <vector <int>> intersection;
vector <int> ans_2;

void print() {
    cout << "Case Number  " << ++T << endl;
    cout << "Number of Customers: " << ans_1 << endl;
    cout << "Locations recommended:";
    for (int ai : ans_2) cout << ' ' << ai;
    cout << endl;
    cout << endl;
}

void solve() {
    for (int mask = 1; mask < (1 << N); mask++) {
        if (__builtin_popcount(mask) != M) continue;
        int sum = 0;
        vector <int> tmp;
        for (int i = 0; i < N; i++)
            if ((mask >> i) bitand 1)
                sum += service[i], tmp.push_back(i + 1);
        for (int i = 0; i < P; i++) {
            int ct = 0;
            for (int j = 0; j + 1 < intersection[i].size(); j++)
                if ((mask >> (intersection[i][j] - 1)) bitand 1)
                    ct++;
            if (ct)
                sum -= (ct - 1) * intersection[i].back();
        }
        if (sum > ans_1 or (sum == ans_1 and tmp < ans_2)) {
            ans_1 = sum;
            ans_2 = tmp;
        }
    }
}

void readCase() {
    for (int i = 0; i < N; i++) cin >> service[i];
    cin >> P;
    for (int i = 0, k; i < P; i++) {
        cin >> k;
        vector <int> towers(k + 1);
        for (int i = 0; i <= k; i++) cin >> towers[i];
        intersection.push_back(towers);
    }
}

void init() {
    intersection.clear();
    ans_1 = 0;
    ans_2.clear();
}

int main() {
    while (cin >> N >> M, N bitor M) {
        init();
        readCase();
        solve();
        print();
    }
    return (0);
}
