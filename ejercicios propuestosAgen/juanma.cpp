#include <iostream>
#include <fstream>
#include "agenDinamica.h"
#include "agen_E-S.h"
//ejercicio 1

template <typename T>
int xNodos(size_t x, const Agen<T>& A){
    return xNodosRec(A.raiz(),x,A);
}
template <typename T>
int xNodosRec(typename Agen<T>::nodo n, size_t x, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        bool si = false;
        if(nNiveles(A.raiz(),profundidadNodoAgen(n,A),A) == x) si = true;
        int aux = 0;
        while(hijo != Agen<T>::NODO_NULO){
            aux += xNodosRec(hijo,x,A);
            hijo = A.hermDrcho(hijo);
        }

        if(si) return 1 + aux;
        else return aux;

    }
}

template <typename T>
int nNiveles(typename Agen<T>::nodo n,int altura, const Agen<T>& A){
      if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int aux = 0;
        bool si = false;
        if(altura == profundidadNodoAgen(n,A)) si = true;
        while(hijo != Agen<T>::NODO_NULO){
            aux += nNiveles(hijo,altura,A);
            hijo = A.hermDrcho(hijo);
        }

        if(si) return 1 + aux;
        else return aux;

    }
}



template <typename T>
int profundidadNodoAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return -1;
    }else{
        return 1 + profundidadNodoAgen(A.padre(n), A);
    }
}





using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura
int main (){
 Agen<tElto> A;
 ifstream fe("agen.dat"); // Abrir fichero de entrada.
 rellenarAgen(fe, A); // Desde fichero.

 fe.close();

 //int n = gradoAgen(A);
//std::cout << n << std::endl;
 //std::cout << profundidadNodoAgen(A, A.hijoIzqdo(A.hijoIzqdo(A.raiz())));

    //podaAgen('g',A);
   //std::cout << alturaNodo(A.raiz(),A);
   //std::cout << minHojas(A.hijoIzqdo(A.hijoIzqdo(A.raiz())), A);
    std::cout << xNodos(3,A) << std::endl;
 //imprimirAgen(A); // En std::cout
} 
