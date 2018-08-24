/**
 * Ejemplo de como crear un 'struct' y como usarlo
 *
 * Problema
 * - Queremos tener un tipo de dato de represente una fracción
 * - Queremos poder ordenar fracciones siguiendo esta relación de orden
 *      a1   a2
 *      -- < --      <->     a1 * b2 < a2 * b1
 *      b1   b2
 * - Queremos poder usar la operación '+' y '*' entre fracciones
 */

/**
 * Recibire un número 'n' seguido de 'n' fracciones
 * Debo imprimir
 * Las fracciones ordenadas
 * La suma de las fracciones
 * El producto de las fracciones
 */

// Para simplificar la solucion, aceptaré que las fracciones tenga 0 en el denominador

#include <bits/stdc++.h>

using namespace std;

struct Fraccion {
    int num, den;
    // Los constructores tienen el mismo nombre que mi estructura
    // Puedo tener más de un constructor
    // Estos se diferenciaran por los parametros que reciban
    Fraccion() {}
    Fraccion(int x, int y) {
        num = x;
        den = y;
    }
    // Puedo sobreescribir el operador '<' para poder usar la función 'sort'
    // - (Fraccion& otra)
    //   Indica que esta función recibirá una referencia de la variable que invoque
    //   este método. Así, no se creará una copia de esa variable para esta función
    //   Lo que se haga con esta variable dentro de la función se vera reflejado en
    //   la variable que la invocó
    // - (const Fraccion otra)
    //   Indica que el valor de la variable 'otra' será constante en ese método
    // - () const {
    //   Indica que este método no cambiará el estado de ningún atributo de la instancia
    //   de esta 'struct' que invoque el método
    bool operator < (const Fraccion& otra) const {
        return num * otra.den < den * otra.num;
    }
    // Si deseo, puedo no usar 'const' y '&'
    // Pero esto será un poco más lento ya que crea copias innecesarias
    // Y al no definir qué es un 'const', no da libertad al compilador de
    // hacer optimizaciones
    Fraccion operator + (Fraccion otra) {
        return Fraccion(num * otra.den + den * otra.num, den * otra.den);
    }
    // Este operador cambiará el estado de la instancia que la invoque
    // por ello no podemos uasr () const {
    void operator *= (const Fraccion& otra){
        num = num * otra.num;
        den = den * otra.den;
    }
    // Tambien puedo escribir funciones ('métodos') para este 'struct'
    void imprimir(string sep) {
        cout << num << '/' << den << sep;
    }
}; // NO OLVIDAR PONER ';' al final de un 'struct'

int n;
vector <Fraccion> arr;

// Si no deseo sobreescribir el operador ('<') en mi 'struct', puedo definirlo
// como una función, así:
bool cmp(const Fraccion& X, const Fraccion& Y) {
    return X.num * Y.den < X.den * Y.num;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num, den;
        cin >> num >> den;
        arr.push_back(Fraccion(num, den));
    }
    sort(arr.begin(), arr.end());
    //sort(arr.begin(), arr.end(), cmp);

    cout << "Las fracciones ordenadas" << endl;
    for (auto fraccion : arr) fraccion.imprimir("  ");
    cout << endl;

    Fraccion suma = Fraccion(0, 1);
    for (auto fraccion : arr) {
        suma = suma + fraccion;
        // Si quisiera usar suma += fraccion
        // Tendria que definir el operador '+='
    }
    cout << "La suma de las fracciones es" << endl;
    suma.imprimir("\n");

    Fraccion producto = Fraccion(1, 1);
    for (auto fraccion : arr) producto *= fraccion;
    cout << "El producto de las fracciones es" << endl;
    producto.imprimir("\n");

    return (0);
}

