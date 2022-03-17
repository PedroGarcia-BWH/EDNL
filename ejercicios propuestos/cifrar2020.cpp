#include <iostream>

//suponemos que el mensaje no esta vacio
std::string descifrar(std::string mensaje){
    Abin<char> A(mensaje.size());
    A.insertarRaiz(mensaje[0]);
    rellenarCifrado(0,A.raiz(),A,mensaje);
}
 //estamos utilizando la vectorial //preguntar a kevin la condicion de que pare a esa altura
void rellenarCifrado(int& indice, typename Abin<char>::nodo n, Abin<char> A, std::string mensaje){
    if(n == Abin<char>::NODO_NULO){

    }
}

