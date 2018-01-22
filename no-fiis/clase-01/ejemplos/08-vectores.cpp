#include <bits/stdc++.h>

using namespace std;

int main() {
    
    /**
     * Hay situaciones en las que necesitamos tener varias variables del mismo tipo
     * Entonces, en ves de declarar por ejemplo 10 int como:
     * int num_1, num_2, num_3, ..., num_10
     * Existe una estructura de datos llamada vector, ella nos permite almacenar datos del mismo tipo
     * Estructura general
     *
     * vector <tipo_de_dato> nombre_del_vector;
     *
     */
    
    vector <int> mi_vector;  // creamos un vector de enteros
    // mi_vector = []
    mi_vector.push_back(3);          // agregamos un elemento
    // mi_vector = [3]
    mi_vector.push_back(5);          // agregamos otro elemento
    // mi_vector = [3, 5]
    mi_vector.push_back(8);          // agregamos otro elemento
    // mi_vector = [3, 5, 8]
    mi_vector.pop_back();            // eliminamos el último elemento
    // mi_vector = [3, 5]
    mi_vector.push_back(10);         // agregmos otro elemento
    // mi_vector = [3, 5, 10]
    
    /**
     * mi_vector = [3, 5, 10]
     * podemos acceder a cada elemento asi:
     * mi_vector[indice]
     * entonces
     * mi_vector[0] : 3
     * mi_vector[1] : 5
     * mi_vector[2] : 10
     * Notemos que (indice) comienza a contarse desde 0
     * Luego, si queremos imprimir todos lo elemento de nuestro vector podemos hacer de estas maneras
     */
    
    // método 1
    for (int elemento : mi_vector) std::cout << elemento << ' ';  // como lo que esta dentro del for es solo una sentencia, puedo omitir los corchetes ({ })
    cout << endl;
    
    // método 2
    for (int indice = 0; indice < mi_vector.size(); indice++) {
        cout << "mi_vector[" << indice << "] = " << mi_vector[indice] << endl;
    }
    
    // notemos que con el método 2 puedes saber el indice que corresponde a cada elemento y el valor en esa posicion
    // mientras que con el método 1 solo el valor asociada a cada posición
    
    /**
     * Más información aqui:
     * http://www.cplusplus.com/reference/vector/vector/
     */
    
    /**
     * Los vectores son en realidad arrays dinámicos que con ciertos métodos (funciones) ya que puedemos ir agregando y quitando elementos
     * Si deseamos un array estatico (tenemos definido el numero de elementos) podemos declararlos así:
     * 
     * tipo_de_dato nombre_de_variable[cantidad_de_elementos]
     *
     * Por ejemplo:
     * int v[100]; 
     * es un array estático de 100 enteros
     *
     * Más información aquí:
     * http://www.cplusplus.com/doc/tutorial/arrays/
     */
    
    return (0);
}