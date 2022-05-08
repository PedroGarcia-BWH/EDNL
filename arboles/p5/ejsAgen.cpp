#include <iostream>
#include <fstream>
#include "agenDinamica.h"
#include "agen_E-S.h"

//ejercicio 4
//suponemos que si el arbol es vacio es true
template <typename T>
bool esTernario(const Agen<T>& A){
    return esTernarioRec(A.raiz(),A);
}

template <typename T>
bool esTernarioRec(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return true;
    }else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int nHijos = 0;
        bool ternario = true;
        while(hijo != Agen<T>::NODO_NULO){
            ternario = ternario && esTernarioRec(hijo,A);
            nHijos++;
            hijo = A.hermDrcho(hijo);
        }

        if((nHijos == 0 || nHijos == 3) && ternario) return true;
        else return false;
    }
}

typedef struct {
    char color; // N, B, Sin color S
    size_t inicio[2], fin[2];
}bc;

//preguntar como se de cuanto es el tamaño de la matriz
char** representarFigura(size_t k, const Agen<bc>& A){
    char m[k][k]; // char m[k][k] = altura(A);
    representarFiguraRec(A.raiz(), m, A );
    return m;

}

void representarFiguraRec(typename Agen<bc>::nodo n, char **m, const Agen<bc>& A){
    if(A.hijoIzqdo(n) == Agen<bc>::NODO_NULO){
        rellenarMatriz(A.elemento(n),m);
    }else{
        typename Agen<bc>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<bc>::NODO_NULO){
            representarFiguraRec(hijo,m,A);
            hijo = A.hermDrcho(n);
        }
    }
}

void rellenarMatriz(bc elem, char **m){
    for(size_t i = elem.inicio[0]; i< elem.fin[0]; i++){
        for(size_t j = elem.inicio[1]; j< elem.fin[1]; j++){
            m[i][j] = elem.color;
        }
    }
}

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura
int main (){
 Agen<tElto> A;
 ifstream fe("agen2.dat"); // Abrir fichero de entrada.
 rellenarAgen(fe, A); // Desde fichero.

 fe.close();

 //int n = gradoAgen(A);
//std::cout << n << std::endl;
 //std::cout << profundidadNodoAgen(A, A.hijoIzqdo(A.hijoIzqdo(A.raiz())));

    cout << esTernario(A);
   
 //imprimirAgen(A); // En std::cout
} 

