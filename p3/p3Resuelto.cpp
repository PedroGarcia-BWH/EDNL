#include <iostream>
#include <fstream>
#include "agenDinamica.h"
#include "agen_E-S.h"
//ejercicio 1
template <typename T>
int gradoAgen(const Agen<T>& A){
    if(A.arbolVacio()){
        return -1;
    }else{
         return gradoAgenRec(A.raiz(),A);
    }
}
template <typename T>
int gradoAgenRec(typename Agen<T>::nodo n ,const agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        int gradoMax = gradoNodo(n,A);
        int gradoAux;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        while (hijo != Agen<T>::NODO_NULO ){
            gradoAux = gradoAgenRec(hijo,A);
            gradoMax = std::max(gradoMax,gradoAux);
            hijo = A.hermDrcho(hijo);
        }

        return gradoMax;
    }
}
//funcion auxiliar para calcular el grado de un nodo solo
template <typename T>
int gradoNodo((typename Agen<T>::nodo n ,const agen<T>& A)){
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    int grado = 0;
    while (hijo != Agen<T>::NODO_NULO ){
        grado++;
        hijo = A.hermDrcho(hijo);
    }

    return grado;
}
//ejercicio 2
template <typename T>
int profundidadNodoAgen(const Agen<T>& A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO){
        return -1;
    }else{
        return 1 + profundidadNodoAgen(A, A.padre(n));
    }
}

//ejercicio3
template <typename T>
int alturaNodo(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return -1;
    }else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int alturaMax = alturaNodo(hijo,A)+1;
        int alturaAux;
        while(hijo != Agen<T>::NODO_NULO){
            alturaAux = alturaNodo(hijo,A) +1;
            alturaMax = std::max(alturaMax,alturaAux);
            hijo = A.hermDrcho(hijo);
        }

        return alturaMax;
    }
}
template <typename T>
int minHojas(typename Agen<T>::nodo n, const Agen<T>& A){
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
        return profundidadNodoAgen(n,A);
    }else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int profMin = minHojas(hijo,A);
        int profAux;
        while(hijo != Agen<T>::NODO_NULO){
            profAux = minHojas(hijo,A);
            profMin = std::min(alturaMax,alturaAux);
            hijo = A.hermDrcho(hijo);
        }

        return profMin;
    }
}
template <typename T>
int desequilibrioAgen (const Agen<T>& A){
    if(A.arbolVacio()) return -1; // no tiene sentido el desequilibrio en un Arbol Vacio
    return desequilibrioAgenRec(A.raiz(),A);
}
template <typename T>
int desequilibrioAgenRec(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int alturaMaxNivel = alturaNodo(hijo,A);
        int profMinNivel = minHojas(hijo,A);
        int alturaAuxNivel, profAuxNivel;

         while(hijo != Agen<T>::NODO_NULO){
            alturaAuxNivel = alturaNodo(hijo,A);
            profAuxNivel = minHojas(hijo,A);
            alturaMaxNivel = std::max(alturaMaxNivel, alturaAuxNivel);
            profMinNivel = std::min(profMinNivel, profAuxNivel);
            hijo = A.hermDrcho(hijo);
        }

        int desMax = alturaMaxNivel - profMinNivel;
        int desAux;


        while(hijo != Agen<T>::NODO_NULO){
            desaux = desequilibrioAgenRec(hijo,)
            desMax = std::max(desMax,desAux);
        
            hijo = A.hermDrcho(hijo);
        }

        return desMax;
    } 
}

//ejercicio 4
//asumimos que el elemento esta 
void podaAgen(int elem, Agen<int>& A){
    podaAgenRec(A.raiz(),elem,A);
}

void podaAgenRec(typename Agen<int>::nodo n, int elem, Agen<int>& A){
    if(n != Agen<int>::NODO_NULO){
        if(A.elemento(n) == elem){
            podaDesdeNodo(n,A);
        }else{
            typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
            while(hijo != Agen<int>::NODO_NULO){
                podaAgenRec(hijo,elem,A);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

void podaDesdeNodo(typename Agen<int>::nodo n, Agen<int>& A){
    if(A.hijoIzqdo(n) == Agen<int>::NODO:NULO){
        if(n == A.raiz()) A.eliminarRaiz();
        if(n == A.hijoIzqdo(A.padre(n))) {
               A.eliminarHijoIzqdo(A.padre(n));
        }else{
            typename Agen<int>::nodo hijo = A.hijoIzqdo(A.padre(n));

            while(A.hermDrcho(hijo) != n){ // buscamos el nodo entre los hijos del padre
            hijo = A.hermDrcho(hijo);
            }

            A.eliminarHermDrcho(hijo);
        }   
    }else
    {
        typename Agen<int>::nodo hijo = A.hijoIzqdo(A.padre(n));

        while(A.hermDrcho(hijo) != n)
        {
            podaDesdeNodo(hijo,A);
            hijo = A.hermDrcho(hijo);
        }
    }
}


using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura
int main (){
 Agen<tElto> A;
 cout << "*** Lectura del árbol A ***\n";
 rellenarAgen(A, fin); // Desde std::cin
 cout << "\n*** Mostrar árbol B ***\n";

int n = gradoAgen(A);
 imprimirAgen(A); // En std::cout
} 
