#include <iostream>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

int esRebelde(typename Abin<bool>::nodo n, const Abin<bool>& A){
    typename Abin<bool>::nodo ancestro = n;
    int elem = 0, noElem = 0;

    while(ancestro != Abin<bool>::NODO_NULO){
        if(A.elemento(ancestro) == A.elemento(n)) elem++;
        else noElem++;
        ancestro = A.padre(ancestro);
    }

    return elem - noElem -1; // si es negativo entonces es rebelde, positivo no es rebelde
}


int nNodosRebeldesRec(typename Abin<bool>::nodo n, const Abin<bool>& A){
    if(n == Abin<bool>::NODO_NULO){
        return 0;
    }else{
        if(esRebelde(n,A) < 0){
            return 1 + nNodosRebeldesRec(A.hijoIzqdo(n),A) + nNodosRebeldesRec(A.hijoDrcho(n),A);
        }else{
            return nNodosRebeldesRec(A.hijoIzqdo(n),A) + nNodosRebeldesRec(A.hijoDrcho(n),A);
        }
    }
}


int nNodosRebeldes(const Abin<bool>& A){
    return nNodosRebeldesRec(A.raiz(),A);
}

/*int esRebelde(typename Abin<bool>::nodo ancestro, int& elem, int& noElem, const Abin<bool>& A,typename Abin<bool>::nodo n){
    if(n == Abin<bool>::NODO_NULO){
        return elem - noElem -1; //como entra el primero el primer eleemnto hayq ue quitarle uno pq siempre sera +1
    }else{
        if(A.elemento(ancestro) == A.elemento(n)) elem++;
        else noElem++;

        return esRebelde(A.padre(ancestro),elem,noElem,A,n);
    }
}*/



using namespace std;
typedef bool tElto;
const tElto fin = NULL; // Fin de lectura.

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
 
} 