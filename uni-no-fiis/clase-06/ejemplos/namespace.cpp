/**
 * Los 'namespace' nos permiten encapsular información (variables, funciones, structs, ...)
 * Así, podemos tener un función con el mismo nombre y que reciba los mismo parametros en
 * distintos 'namespace' sin que haya ambigüedad entre ellas
 * Usar 'namespace' puede ayudarnos a hacer nuestro código más organizado
 */

#include <bits/stdc++.h>

using namespace std;

namespace Espanol {
    void saludar() {
        cout << "Hola mundo" << endl;
    }
}

namespace Ingles {
    void saludar() {
        cout << "Hello world" << endl;
    }
}

namespace Marginal {
    void saludar() {
        cout << "WASAAAAA" << endl;
    }
}

void saludar() {
    cout << "Hola!" << endl;
}

int main() {
    saludar(); // equivalente ::saludar();
    Espanol::saludar();
    Ingles::saludar();
    Marginal::saludar();
    return (0);
}
