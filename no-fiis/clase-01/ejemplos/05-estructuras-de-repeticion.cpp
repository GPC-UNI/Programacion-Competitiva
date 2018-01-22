#include <bits/stdc++.h>

using namespace std;

int main() {
    
    /**
     * Existen 3 tipos de estructuras de repetición en c++
     * for
     * while
     * do/while
     */
    
    /**
     * for
     * estructura general
     *
     * for (inicialización; condiciones límites; actualización) {
     *     Has algo;
     * }
     *
     * Nota 1:
     * 1. Se inicializan las variables declaradas en (inicializacion)
     * 2. Se verifica si se cumplen (condiciones límites) [si se cumple se continua con los siguientes pasos, sino ahi termina el bucle]
     * 2. Se ejecuta todo lo que este dentro del for
     * 3. Se hace lo que este dentro de (actualización)
     * 4. Se regresa al paso 2
     */
    
    for (int i = 0; i < 3; i++) {
        cout << "i = " << i << endl;
    }
    
    /**
     * while
     * estructura general
     *
     * while (condicion) {
     *   has algo;
     * }
     *
     * Nota 1:
     * 1. Se verifica que se cumple (condición) [si se cumple se continua al paso 2, sino ahi termina el bucle]
     * 2. Se ejecuta todo lo que esta dentro del while y se regresa al paso 1
     */
    
    int z = 6;
    while (z != 0) {
        cout << "z = " << z << endl;
        z--;
    }
    
    /**
     * do / while
     * estrucutura general
     *
     * do {
     *     has algo;
     * } while (condicion);
     *
     * Nota 1:
     * 1. Se ejecuta todo lo que este dentro del do
     * 2. Se verifica la (condicion) [si se cumple se vuelve al paso 1, sino ahi termina el bucle]
     */
    int a = 3;
    do {
        cout << "a = " << a << endl;
        a--;
    } while (a); // mientras a sea distinto de 0
    
    /**
     * Nota 1:
     * En realidad existen más 'tipos de estruturas de control'
     * for_each, ... (pero en realidad son equivalentes a las mostradas líneas arriba)
     * Mas información aquí:
     * http://www.cplusplus.com/doc/tutorial/control/
     */
    
    return (0);
}