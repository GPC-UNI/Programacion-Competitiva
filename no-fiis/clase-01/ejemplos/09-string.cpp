#include <bits/stdc++.h>

using namespace std;

int main() {
    /**
     * Un string guarda un vector de chars, es decir palabras
     * Por ejemplo, si quisiera guardar la palabra "Hola mundo" puedo hacerlo así
     */
    string cadena_1 = "Hola mundo";
    /**
     * Como un string es un vector de chars, entonces en realidad tenemos lo siguiente
     * cadena_1 = ['H', 'o', 'l', 'a', ' ', 'm', 'u', 'n', 'd', 'o']
     * Luego, al igual que con los vectores podemos acceder a un elemento en particular
     * considerando que las posiciones se cuentan desde 0
     */
    cout << "Primer elemento de la cadena_1 es : " << cadena_1[0] << endl;
    
    // Podemos iterar sus elemento al igual que con los vectores
    
    // método 1
    for (char elemento : cadena_1) cout << elemento;
    cout << endl;
     
    // método 2
    for (int pos = 0; pos < cadena_1.size(); pos++) {
        cout << "cadena_1[" << pos << "] = " << cadena_1[pos] << endl;
    }
    
    /**
     * Pero, tal como mencionamos, un char en realidad es un número
     * entonces podemos obtener que número esta asociado a cada letra forzando la conversion de char a int
     */
    for (int pos = 0; pos < cadena_1.size(); pos++) {
        cout << "cadena_1[" << pos << "] = " << (int) cadena_1[pos] << endl;
    }
    
    /**
     * Por otro lado, una situación común en CP es tener que recorrer las letras del abecedario
     * Si bien podemos hacerlo así:
     * string abecedario = "abcd....xyz";
     * for (char letra : abecedario) cout << letra << endl;
     * Una forma más sencilla se puede lograr utilizando el hecho de que el número asociado a las letras
     * del abecedario están distribuidos de forma continua
     *
     * 'a' : 97
     * 'b' : 98
     * 'c' : 99
     * .
     * .
     * .
     * 'x' : 120 
     * 'y' : 121
     * 'z' : 122
     */
    // recorriendo el abecedario
    for (char ch = 'a'; ch <= 'z'; ch++) cout << ch << endl;
    
    /**
     * Análogamente para las letras mayúsculas tenemos:
     *
     * 'A' : 65 
     * 'B' : 66
     * 'C' : 67
     * .
     * .
     * .
     * 'X' : 88
     * 'Y' : 89
     * 'Z' : 90
     */
    for (char ch = 'A'; ch <= 'Z'; ch++) cout << ch << endl;
    
   
    /**
     * Nota 1: En CP la entrada es en Inglés asi que no se considera la ñ
     */
    
            /**
             * Además, en la actualidad el estándar de esas equivalencias entre números y caracteres
             * ya no se hace por el ASCII, se hacer por el UNICODE
             * Y como un char solo aguanta 2 ^ 8 números y además hay caracteres complicados en algunos lenguajes que están compuestas por varias letras
             * suceden situaciones en la que un caracter se guarda en más de un char, por ejemplo:
             */

            string cadena_2 = "á";

            // Tenemos un solo elemento, pero si imprimos en tamaño de la cadena notamos que nos da 2
            cout << "El tamaño de cadena_2 es : " << cadena_2.size() << endl;

            // Por ello, en general, la forma más segura de recorrer un string es
            for (char elemento : cadena_2) cout << elemento;
            cout << endl;

            // Pues, con este método nos saldrán resultados extraños en estas situaciones
            for (int pos = 0; pos < cadena_2.size(); pos++) {
                cout << "cadena_2[" << pos << "] = " << cadena_2[pos] << endl;
            }

            // Podemos observar mejor el porqué si vemos el número asociado al caracter 'á'
            for (int pos = 0; pos < cadena_2.size(); pos++) {
                cout << "cadena_2[" << pos << "] = " << (int) cadena_2[pos] << endl;
            }
            // cadena_2[0] = -61
            // cadena_2[1] = -95
            // notamos que 'á' esta guarda como una tupla de números (-61, -95) y no como un solo número que es el caso 'normal'

            /**
             * Esto es solo como cultura general y para responder a lo que preguntaron
             * En CP la entrada siempre es en Inglés asi que solo vienen caracteres a los que estan asociados un solo número
             * por lo que no hay necesidad de preocuparse de esta cuestión
             */
     
    /**
     * Más informacion de strings aquí:
     * http://www.cplusplus.com/reference/string/string/
     * Además, tambien es bueno que conoscan algunas funciones básicas usadas con chars, información aquí:
     * http://www.cplusplus.com/reference/cctype/
     */
    
    return (0);
}