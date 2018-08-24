/**
 * link : http://codeforces.com/problemset/problem/593/A
 * Problema:
 * Sea A = {word_1, word_2, ..., word_n} un conjunto de palabras
 * Sea B = {word_1, word_2, ..., word_m} [1 <= m <= n] un subconjunto de A
 * Sea length(word_i) = "tamaño de `word_i`"
 * Sea f(B) = suma {length(word_i) / word_i este en B}
 * Debes encontrar maximo(f(B)) para todo B subconjunto de A
 * que cumple que todos sus elementos esten formados por a lo mucho 2 unicos caracteres
 */

/**
 * Ejemplo:
 * Para A = {"abb", "cacc", "aaa", "bbb"}
 * Los B que cumplen las condiciones, son:
 * B_1 = {"abb"}                          f(B_1) = 3
 * B_2 = {"abb", "aaa"}                   f(B_2) = 6
 * B_3 = {"abb", "aaa", "bbb"}            f(B_3) = 9
 * B_4 = {"aaa"}                          f(B_4) = 3
 * B_5 = {"aaa", "bbb"}                   f(B_5) = 6
 * B_6 = {"bbb"}                          f(B_6) = 3
 * B_7 = {"cacc"}                         f(B_7) = 4
 * B_8 = {"cacc", "aaa"}                  f(B_8) = 7
 * Encontes, la respuesta es maximo(f(B_1), f(B_2), ..., f(B_8)) = 9
 */

/**
 * Solucion:
 * Sea B un subconjunto de A, si suponemos que B cumple las condiciones del problema
 * Entonces exiten dos caracteres, sean (ch_1, ch_2) tal que todos los elementos de B estan formados por ellos
 * Pero ch_1 y ch_2 solo pueden tomar estos valores ('a', 'b', ..., 'y', 'z')
 * Entonces, podemos buscar con todas las configuraciones posibles de (ch_1, ch_2) y encontrar
 * subconjuntos B con la propiedad buscada y con ello encontrar maximo(f(B))
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 110;

int n, ans;
string word[MAX_N];

bool isValid(int id, char ch_1, char ch_2) {
    for (int pos = 0; pos < word[id].size(); pos++)
        if (word[id][pos] != ch_1 and word[id][pos] != ch_2) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> word[i];
    for (char ch_1 = 'a'; ch_1 <= 'z'; ch_1++)
        for (char ch_2 = ch_1; ch_2 <= 'z'; ch_2++) {
            int sum = 0;
            for (int id = 0; id < n; id++) sum += isValid(id, ch_1, ch_2) * word[id].size();
            ans = max(ans, sum);
        }
    cout << ans << endl;
    return (0);
}