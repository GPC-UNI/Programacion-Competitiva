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
     * estructura general del for
     *
     * for (inicialización; condiciones límites; actualización) {
     *     Has algo;
     * }
     *
     * Nota 1:
     * 1. Se inicializan las variables declaradas en (inicialización)
     * 2. Se verifica si se cumplen (condiciones límites) [si se cumple se continúa con los siguientes pasos, sino ahí termina el bucle]
     * 2. Se ejecuta todo lo que este dentro del for
     * 3. Se hace lo que este dentro de (actualización)
     * 4. Se regresa al paso 2
     */
    
    for (int i = 0; i < 3; i++) {
        cout << "i = " << i << endl;
    }
    
    /**
     * estructura general del while
     *
     * while (condición) {
     *   has algo;
     * }
     *
     * Nota 1:
     * 1. Se verifica que se cumple (condición) [si se cumple se continua al paso 2, sino ahí termina el bucle]
     * 2. Se ejecuta todo lo que esta dentro del while y se regresa al paso 1
     */
    
    int z = 6;
    while (z != 0) {
        cout << "z = " << z << endl;
        z--;
    }
    
    /**
     * estrucutura general del do / while
     *
     * do {
     *     has algo;
     * } while (condición);
     *
     * Nota 1:
     * 1. Se ejecuta todo lo que este dentro del do
     * 2. Se verifica la (condición) [si se cumple se vuelve al paso 1, sino ahi termina el bucle]
     */
    int a = 3;
    do {
        cout << "a = " << a << endl;
        a--;
    } while (a); // mientras a sea distinto de 0
    
    /**
     * Nota 1:
     * En realidad existen más 'tipos de estruturas de repetición'
     * for_each, ... (pero todas sirven para lo mismo : repetir sentencias)
     * Mas información de estructuras de repetición aquí:
     * http://www.cplusplus.com/doc/tutorial/control/
     */
    
    return (0);
}