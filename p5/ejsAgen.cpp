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

    cout << esTernario(A);
   
 //imprimirAgen(A); // En std::cout
} 

