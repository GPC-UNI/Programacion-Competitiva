#include <bits/stdc++.h>

using namespace std;

int main() {
    /**
     * Probllema
     * Recibiremos un número t
     * Si t es 1 recibiremos 3 números y tenemos que imprimir la suma de ellos
     * Si t es 2 recibiremos 2 números y tendremos que imprimir el producto
     * Si t es 3 recibiremos un numeros y tendremos que imprimir ese numero elevado al cuadrado
     *
     */
    
    int t, num_1, num_2, num_3;
    cin >> t;
    if (t == 1) {
        cin >> num_1 >> num_2 >> num_3;
        cout << num_1 + num_2 + num_3 << endl;
    }
    else if (t == 2) {
        cin >> num_1 >> num_2;
        cout << num_1 * num_2 << endl;
    }
    else if (t == 3) {
        cin >> num_1;
        cout << num_1 * num_1 << endl;
    }
    return (0);
}