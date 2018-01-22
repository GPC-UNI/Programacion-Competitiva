#include <bits/stdc++.h>

using namespace std;

int main() {
    /**
     * Las estructuras de control permiten evaluar ciertas condiciones de acuerdo a las cuales decidir que
     * deberá hacer el programa en ejecución
     *
     * En c++ existren 3 formas de hacer ello
     * - if / else if / else
     * - switch
     * - Operador ternario exp_1 ? exp_2 : exp_3
     */
     
     
    /**
     * Estructura general:
     *
     * if (condicion_1) {
     *     Has algo
     * }
     * else if (condicion_2) {
     *     Has otra cosa;
     * }
     * else if (condicion_3) {
     *     Has otra cosa;
     * }
     * .
     * -
     * .
     * else if (condicion_n) {
     *     Has otra cosa;
     * }
     * else {
     *     Has algo por defecto
     * }
     *
     */
    
    int x = 2;
    if (x == 3) {
        cout << "x = 3" << endl;
    }
    else if (x == 2) {
        cout << "x = 2" << endl;
    }
    else cout << "x = " << x << endl;
    /**
     * Nota 1: El uso de los (else if) y (else) es opcional
     * Nota 2: Cuando lo que esta dentro de un (if), (else if), (else), (for), (while), ... es una sola sentencia, se pueden omitir los corchetes ({ })
     */
    
    /**
     * Estrucutra general:
     *
     * switch(expresion_base) {
     *     case (expresion_1):
     *         has algo;    
     *         break;
     *     case (expresion_2):
     *         has algo;
     *         break;
     *     .
     *     .
     *     .
     *     case (expresion_n):
     *         has algo;
     *         break;
     *     default:
     *         has algo;
     *         break;
     * }
     *
     *
     * Nota, en cada caso se evalua si (expresion_base == expresion_i) [i = 1, 2, 3, ..., n]
     */
    
    int expresion_base = 14;
    switch (expresion_base) {
        case (1):
            cout << "expresion_base = 1" << endl;
            break;
        case (2):
            cout << "expresion_base = 2" << endl;
            break;
        default:
            cout << "expresion_base = " << expresion_base << endl;
            break;
    }
    
    /**
     * Muchas veces tenemos esta situacion
     * if (condicion) {
     *     expresion_1;
     * }
     * else {
     *     expresion_2;
     * }
     *
     * Para simplificar eso existe el operador ternario
     * condicion ? expresion_1 : expresion_2
     */
    
    int z;
    if (3 == 2) {
        z = 100;
    }
    else {
        z = 200;
    }
    
    // Lo anterior es equivalente a
    (3 == 2) ? z = 100 : z = 200;
    
    cout << "z = " << z << endl;
    
    /**
     * Nota 1: En realidad existe una cuarda estructura de control (goto), pero esta extremadamente recomendado el no usarlo
     * Mas información de estructuras de control aquí:
     * http://www.cplusplus.com/doc/oldtutorial/control/
     */
    
    return (0);
}