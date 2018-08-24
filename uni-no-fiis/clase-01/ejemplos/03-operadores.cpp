#include <bits/stdc++.h>

using namespace std;

int main() {
    
    /**
     * Operarador asignación (=)
     * Asigna una expresión (número, cálculo, etc) a una variable
     */
    int variable = 3;
    
    /**
     * Operador comparación de igualdad (==)
     * Compara si dos expresiones son iguales
     * retorna true si son iguales y false en caso contrario
     */
    bool expresion_1 = (3 == 3);
    
    /**
     * Operador comparación de desigualdad (!=)
     * Compara si dos expresiones son distintas
     * retorna true si son distintos y false en caso contrario
     */
    bool expresion_2 = (4 != 3);
    
    /**
     * Nota 1: El número 0, el punto nulo (NULL, nullptr) y una cadena vacia se evalúan como false, todo lo demás es true
     * Entonces, si casteo (bool) 0 : false
     * (bool) 1 : true
     * (bool) 1232434 : true
     */
    
    /**
     * Operadores de relación de orden (<, >, <=, >=)
     * Por ejemplo (a > b) compara si a es mayor que b, retorna true si es verdado y false en caso contrario
     */
    bool expresion_3 = (1 <= 1);
    
    /**
     * Las operaciones básicas que uno requiere hacer son:
     * Suma (+)
     * Resta (-)
     * Multiplicacion (*)
     * Division (/)
     * Módulo (%)
     * Exponenciación
     * Raiz cuadrada
     */
    
    /**
     * Suma (+)
     * Se puede realizar entre distintos tipos de datos numéricos (int, long, long long, float, double, long double)
     * Se evalua de izquierda a derecha y se va manteniendo el resultado en el tipo de dato de mayor jerarquía (int < long < long long < float < double < long double)
     * Al final el resultado se convierte al tipo de dato de la variable en la que se guarda
     */
    int res_1 = 12 + 45;
    // 14 + 12.4 = 26.4 (double) [ya que 12.4 es un double y este tiene mayor jerarquia que un int]
    // pero como el resultado lo guardamos en una variable int, entonces 26.4 se vuelve un int y resulta 26 (int)
    int res_2 = 14 + 12.4;
    
    /**
     * Resta (-)
     * Las mismas consideraciones de la suma
     */
    int res_3 = 12 - 79;
    
    
    /**
     * Multiplicación (*)
     * Las mismas consideraciones anteriores
     */
    int res_4 = 12 * 78;
    
    /**
     * Division (/)
     * Las mismas consideraciones anteriores
     * Además, ten cuidado de no dividir por 0 o te arrojará un error
     * Nota: Si durante la ejecución de tu programa se realiza una división por 0, el jurado te arrojará un Runtime Error (RE)
     */
    int res_5 = 10 / 5;
    
    /**
     * Módulo (%)
     * a % b = resto de a / b
     * Se calcula así: a % b = a - b * (a / b), donde a / b es división entera
     * Como indirectamente se calcula la división a / b, entonces b tienes que ser distinto de 0 o te saldrá un error
     * Nota 1: Esto se realiza entre enteros, hay formas para hacerlo con números flotantes pero más adelante veremos eso
     */
    int res_6 = 23 % 8;
    
    
    /**
     * Nota:
     * Para los operadores aritméticos anteriores existe una abreviación cuando se quiere guardar el resultado en una variable
     * variable = variable operacion expresion
     * es equivalente a
     * variable operacion= expresion
     * Por ejemplo:
     * x = 3;
     * x = x + 10;
     * Es lo mismo que:
     * x = 3;
     * x += 10;
     * Además, para:
     * x += 1;
     * su equivalente es
     * x++;
     * Y para:
     * x -= 1;
     * su equivalente es
     * x--;
     */
    
    /**
     * Exponenciación 
     * No es una operación aritmética básica en c++
     * puedes calcularla con la función pow(a, b) = a ^ b
     * o puedes hacer un for para obtenerla
     * Nota 1: pow(a, b) te arrojará el resultaddo en (double)
     * Nota 2: Si deseas obtener el resultado en int puedes forzar la conversión por medio del casteo
     */
    
    double res_7 = pow(3, 3);
    int res_8 = (int) res_7; // esto es un casteo, estoy forzando a que res_7 que es un double se vuelva un int
    
    /**
     * Raiz cuadrada
     * Puedes obtenerla con la función sqrt(a)
     * Nota 1: sqrt(a) te arroja un (double)
     */
    double res_9 = sqrt(10);
    
    /**
     * Nota:
     * Otra operación comúnmente usada es la de hallar un máximo o un mínimo
     * Para ello puedes usar las funciones max y min
     * Puedes chequear el uso de estas funciones aquí:
     * http://www.cplusplus.com/reference/algorithm/max/
     * http://www.cplusplus.com/reference/algorithm/min/
     *
     * Más información de operadores aquí:
     * http://en.cppreference.com/w/cpp/language/operator_arithmetic
     * http://www.cplusplus.com/doc/tutorial/operators/
     * http://www.cplusplus.com/reference/cmath/pow/
     * http://www.cplusplus.com/reference/cmath/sqrt/
     */
    
    return (0);
}