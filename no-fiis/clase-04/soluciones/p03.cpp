/**
 * LINK DEL PROBLEMA:
 * http://codeforces.com/problemset/problem/114/B
 *
 * SOLUCIÓN:
 * Tenemos un array de 'n' elementos: nombre[1], nombre[2], ..., nombre[n]
 * Y 'm' pares: 'nombre_1', 'nombre_2' de personas que no se llevan bien
 * Luego, tenemos que encontrar un subconjunto del array dado tal que
 * no hayan 2 pares de individuos que se odien y que el conjunto sea tan 
 * grande como sea posible.
 * Y la respuesta sera el tamaño de ese conjunto, seguido de sus elementos
 * impresos en orden lexicográfico
 * Entonces, podemos usar la misma táctica del problema 1: Crear una mascara
 * de 'n' bits, iterar por todas sus posibles configuraciones, ver si el 
 * subconjunto asociado cumple las condiciones dadas y de ser así, actualizar
 * la respuesta de ser necesario.
 *
 * COMPLEJIDAD
 * O(m * 2 ^ n)
 *
 * DETALLES DE LA IMPLEMENTACIÓN:
 * EL uso del 'map' es para poder asociar un indice a cada nombre dado
 * La razón de ordenar el array dado antes de asociarle un indice a cada nombre
 * es para que cuando iteremos la 'mask' resultante como respuesta, obtengamos
 * los nombres en orden lexicográfico
 * hate[i] = {order[name_1], order[name_2]} = make_pair(order[name_1], order[name_2])
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 16, MAX_M = 120, OFFSET = 5;

int n, m, ans_k, ans_mask;
map <string, int> order;
pair <int, int> hate[MAX_M + OFFSET];
string name_1, name_2, name[MAX_N + OFFSET];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> name[i];
    sort(name, name + n);
    for (int i = 0; i < n; i++) order[name[i]] = i;
    for (int i = 0; i < m; i++) {
        cin >> name_1 >> name_2;
        hate[i] = {order[name_1], order[name_2]};
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        bool valid = true;
        for (int i = 0; i < m; i++)
            if ((mask >> hate[i].first) bitand 1 and (mask >> hate[i].second) bitand 1)
                valid = false;
        if (valid and ans_k < __builtin_popcount(mask)) {
            ans_k = __builtin_popcount(mask);
            ans_mask = mask;
        }
    }
    cout << ans_k << endl;
    for (int bit = 0; bit < n; bit++) if ((ans_mask >> bit) bitand 1) cout << name[bit] << endl;
    return (0);
}
