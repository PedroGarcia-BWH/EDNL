#include <iostream>
#include <fstream>
#include "agenDinamica.h"
#include "agen_E-S.h"
//ejercicio 1

template <typename T>
Agen<T> reflejado(const Agen<T>& A){
    Agen<T> B;
    if(!A.arbolVacio()){
        B.insertarRaiz(A.elemento(A.raiz()));
        reflejadoRec(A.raiz(), B.raiz(), A, B);
    }

    return B;
}

template <typename T>
void reflejadoRec(typename Agen<T>::nodo nA, typename Agen<T>::nodo nB, const Agen<T>& A, Agen<T>& B){
    if(nA != Agen<T>::NODO_NULO && nB != Agen<T>::NODO_NULO){
        typename Agen<T>::nodo hijoA = A.hijoIzqdo(nA);
        if(hijoA != Agen<T>::NODO_NULO) {
            B.insertarHijoIzqdo(nB, A.elemento(hijoA));
             typename Agen<T>::nodo hijoB = B.hijoIzqdo(nB);
             reflejadoRec(hijoA,hijoB,A,B);
             hijoA = A.hermDrcho(hijoA);
             while(hijoA != Agen<T>::NODO_NULO){
                 B.insertarHijoIzqdo(nB, A.elemento(hijoA));
                reflejadoRec(hijoA,hijoB,A,B);

                 hijoA = A.hermDrcho(hijoA);
                 hijoB = B.hijoIzqdo(nB);
             }
        }
       
    }
}



using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura
int main (){
 Agen<tElto> A, B;
 ifstream fe("agen.dat"); // Abrir fichero de entrada.
 rellenarAgen(fe, A); // Desde fichero.

 fe.close();

 //int n = gradoAgen(A);
//std::cout << n << std::endl;
 //std::cout << profundidadNodoAgen(A, A.hijoIzqdo(A.hijoIzqdo(A.raiz())));

    //podaAgen('g',A);
   //std::cout << alturaNodo(A.raiz(),A);
   //std::cout << minHojas(A.hijoIzqdo(A.hijoIzqdo(A.raiz())), A);
    //std::cout << xNodos(3,A) << std::endl;
    B= reflejado(A);
 imprimirAgen(B); // En std::cout
} 
