#include <bits/stdc++.h>

using namespace std;

int main() {
    

    /**
     * int
     * Guarda números enteros en el rango (-2 ^ 32, 2 ^ 32) lo cual es aproximadamente [-2 * 10 ^ 9, 2 * 10 ^ 9]
     * Por defecto cuando inicializamos una variable como un número entero se guarda como un int
     */
    int num_1 = 10;
    
    /**
     * long long
     * Guarda números enteros en el rango (-2 ^ 64, 2 ^ 64) lo cual es aproximadamente [-9 * 10 ^ 18, 9 * 10 ^ 18]
     * úsalo si requieres guardar números que no entran en el rango de un int
     * Nota 1: Para iniciar un número como un long long de manera directa debes agregar 'LL' al final del número, por ejemplo
     * 12LL : 12 (long long) mientras que 12 : 12 (int)
     * Nota 2: long long == long long int
     */
    long long num_2 = 10000000000000000LL;
    
    /**
     * long
     * Guarda números enteros en un rango mayor al de un int, pero menor al de un long long
     * aunque esto por lo general varia entre cada computadora
     * si te ves en la tentativa de usarlo, prefiere usar un long long
     */

    
    /**
     * Si deseas revisar los límites de cada tipo por ti mism@, puedes llamar a las siguientes constantes
     * INT_MIN   // mínimo int que se puede guardar
     * INT_MAX   // máximo int que se puede guardar
     * LONG_MIN  // mínimo long que se puede guardar
     * LONG_MAX  // máximo long que se puede guardar
     * LLONG_MIN // mínimo long long que se puede guardar
     * LLONG_MAX // máximo long long que se puede guardar
     * Más información de esto aquí:
     * http://www.cplusplus.com/reference/climits/
     */
    
    
    /**
     * float
     * Guarda números decimales de hasta 6 dígitos decimales con precisión
     * Nota 1: Para iniciar un número como un flotante se agrega una F al final del número
     */
    float num_4 = 12.4F;
    
    /**
     * double
     * Guarda números decimales de hasta 15 dígitos decimales con precisión
     * Nota 1: Por defecto los decimales se guardan como double
     */
    double num_5 = 234554.54554;
    
    
    /**
     * long double
     * Guarda números decimales de hasta 18 dígitos decimales con precisión
     * Nota 1: Para iniciar un número como long double se agrega una L al final del número
     */
    long double num_6 = 1324345.5465656565655L;
    
    /**
     * Si deseas ver más sobre los limites de cada tipo flotante revisa la documentación de ellos aqui:
     * http://www.cplusplus.com/reference/cfloat/
     */
    
    
    /**
     * char
     * Un char guarda números entre (-2 ^ 8, 2 ^ 8), pero a cada número esta asociado una letra
     * y por defecto al imprimirlo te mostrará la letra asociada y no el número
     * Por lo general se usan para guardar letras minúsculas, mayúsculas, espacios, saltos de linea ('\n'), dígitos y
     * signos de interrogacion o exclamación, para otros simbolos se prefiere utilizar string
     */
    char ch = 'M';
    
    
    /**
     * bool
     * Un bool guarda una expresión booleanda (true o false) [verdadero o falso]
     */
    bool ejemplo_1 = true;
    bool ejemplo_2 = false;
    
    /**
     * Más info de tipos de datos aquí:
     * http://www.cplusplus.com/doc/tutorial/variables/
     */
    
    return (0);
}