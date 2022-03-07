#include <iostream>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"
//#include "AbinVectorial.h"
//#include "AbinRelativo.h"

template <typename T>
int nodosVerdes(Abin<T> A){
    return nodosVerdesRec(A.raiz(),A);
}
template <typename T>
int nodosVerdesRec(typename Abin<T>::nodo n, Abin<T> A){
    if(n == Abin<T>::NODO_NULO){
        return 0; 
    }else{
        typename Abin<T>::nodo hizq = A.hijoIzqdo(n);
        typename Abin<T>::nodo hder = A.hijoDrcho(n);
        if(( hizq != Abin<T>::NODO_NULO && hder != Abin<T>::NODO_NULO) && 
        ((A.hijoIzqdo(hizq) != Abin<T>::NODO_NULO && A.hijoDrcho(hizq) != Abin<T>::NODO_NULO && A.hijoIzqdo(hder) != Abin<T>::NODO_NULO && A.hijoDrcho(hder) == Abin<T>::NODO_NULO) ||
        (A.hijoIzqdo(hizq) != Abin<T>::NODO_NULO && A.hijoDrcho(hizq) != Abin<T>::NODO_NULO && A.hijoIzqdo(hder) == Abin<T>::NODO_NULO && A.hijoDrcho(hder) != Abin<T>::NODO_NULO) ||
        (A.hijoIzqdo(hizq) != Abin<T>::NODO_NULO && A.hijoDrcho(hizq) == Abin<T>::NODO_NULO && A.hijoIzqdo(hder) != Abin<T>::NODO_NULO && A.hijoDrcho(hder) != Abin<T>::NODO_NULO) ||
        (A.hijoIzqdo(hizq) == Abin<T>::NODO_NULO && A.hijoDrcho(hizq) != Abin<T>::NODO_NULO && A.hijoIzqdo(hder) != Abin<T>::NODO_NULO && A.hijoDrcho(hder) != Abin<T>::NODO_NULO) )){
            
            return 1 + nodosVerdesRec(A.hijoIzqdo(n),A) + nodosVerdesRec(A.hijoDrcho(n),A);
        }else{
            return nodosVerdesRec(A.hijoIzqdo(n),A) + nodosVerdesRec(A.hijoDrcho(n),A);
        }
    }
}

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.
int main (){
 Abin<tElto> A, B;
 cout << "*** Lectura del árbol binario A ***\n";
 rellenarAbin(A, fin); // Desde std::cin
 ofstream fs("abin.dat"); // Abrir fichero de salida.
 imprimirAbin(fs, A, fin); // En fichero.
 fs.close();
 cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";
 cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
 ifstream fe("abin.dat"); // Abrir fichero de entrada.
 rellenarAbin(fe, B); // Desde fichero.
 fe.close();
 cout << "\n*** Mostrar árbol binario B ***\n";
 imprimirAbin(B); // En std::cout

 cout << "Nodos verdes: " << nodosVerdes(A);

} 

