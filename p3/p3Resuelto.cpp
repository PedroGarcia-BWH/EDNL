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
int gradoAgenRec(typename Agen<T>::nodo n ,const Agen<T>& A){
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
int gradoNodo(typename Agen<T>::nodo n ,const Agen<T>& A){
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
/*template <typename T>
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
        return profundidadNodoAgen(A,n);
    }else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int profMin = minHojas(hijo,A);
        int profAux;
        while(hijo != Agen<T>::NODO_NULO){
            profAux = minHojas(hijo,A);
            profMin = std::min(profMin, profAux);
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
        std::cout  << alturaMaxNivel << " " << A.elemento(n)<< std::endl;
        std::cout  << profMinNivel << " " << A.elemento(n)<< std::endl;

        std::cout  << desMax << " " << A.elemento(n)<< std::endl;
        int desAux;

        hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            desAux = desequilibrioAgenRec(hijo,A);
            desMax = std::max(desMax,desAux);
        
            hijo = A.hermDrcho(hijo);
        }

        return desMax;
    } 
}*/

//ejercicio 4
//asumimos que el elemento esta 

void podaDesdeNodo(typename Agen<char>::nodo& n, Agen<char>& A){
    if(A.hijoIzqdo(n) == Agen<char>::NODO_NULO){
        
        if(n == A.raiz()) A.eliminarRaiz();
        if(n == A.hijoIzqdo(A.padre(n))) {
               A.eliminarHijoIzqdo(A.padre(n));
        }else{
            typename Agen<char>::nodo hijo = A.hijoIzqdo(A.padre(n));

            while(A.hermDrcho(hijo) != n){ // buscamos el nodo entre los hijos del padre
            hijo = A.hermDrcho(hijo);
            }

            A.eliminarHermDrcho(hijo);
        }   
    }else
    {
        typename Agen<char>::nodo hijo = A.hijoIzqdo(n);

       while(hijo != Agen<char>::NODO_NULO)
        {
            podaDesdeNodo(hijo,A);
            hijo = A.hermDrcho(hijo);
        }
    }
}

void podaAgenRec(typename Agen<char>::nodo n, char elem, Agen<char>& A){
    
    if(n != Agen<char>::NODO_NULO){
        if(A.elemento(n) == elem){
            
            podaDesdeNodo(n,A);
             
        }else{
            typename Agen<char>::nodo hijo = A.hijoIzqdo(n);
            while(hijo != Agen<char>::NODO_NULO){
                podaAgenRec(hijo,elem,A);
                hijo = A.hermDrcho(hijo);
                
            }
        }
    }
}
void podaAgen(char elem, Agen<char>& A){
    podaAgenRec(A.raiz(),elem,A);
}



/*template <typename T>
int desequilibrioAgen(Agen<T>& A){
    if(A.arbolVacio()){
        return 0;
    }
    return desequilibrioAgen_Rec(A.raiz(), A);
}

template <typename T>
int desequilibrioAgen_Rec(typename Agen<T>::nodo n, Agen<T>& A){
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        int diferencia = desequilibrioNivel(A.hijoIzqdo(n), A);
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while (hijo != Agen<T>::NODO_NULO){
            diferencia = std::max(diferencia, desequilibrioAgen_Rec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return diferencia;
    }
}

template<typename T>
int desequilibrioNivel(typename Agen<T>::nodo n, Agen<T>& A){
    int minAlt, maxAlt = alturaNodo(n, A);
    minAlt = alturaNodo(n, A);
    if(A.hermDrcho(n) != Agen<T>::NODO_NULO){
        typename Agen<T>::nodo herm = A.hermDrcho(n);
        while(herm != Agen<T>::NODO_NULO){
            if(minAlt > alturaNodo(herm, A)) minAlt = alturaNodo(herm, A);
            if(maxAlt < alturaNodo(herm, A)) maxAlt = alturaNodo(herm, A);
            herm = A.hermDrcho(herm);
        }
    }
    return maxAlt - minAlt;
}

template <typename T>
int alturaNodo(typename Agen<T>::nodo n, Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        int altura = 0;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while (hijo != Agen<T>::NODO_NULO){
            altura = std::max(altura, alturaNodo(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + altura;
    }
}*/



template <typename T>
int desequilibrioAgen(Agen<T>& A){
    if(A.arbolVacio()){
        return 0;
    }else{
        return desequilibrioAgen_Rec(A.raiz(),A);
    }
}

template <typename T>
int desequilibrioAgen_Rec(typename Agen<T>::nodo n,Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        int desequilibrio = calcularDesequilibrio(n,A);
        if(A.hijoIzqdo(n) != Agen<T>::NODO_NULO){
            typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
            while(hijo != Agen<T>::NODO_NULO){
                desequilibrio = std::max(desequilibrio,desequilibrioAgen_Rec(hijo,A));
                hijo = A.hermDrcho(hijo);
            }

        }

        return desequilibrio;
    }

}

template <typename T>
int calcularDesequilibrio(typename Agen<T>::nodo n,Agen<T>& A){

    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
        return 0;
    }else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int altMax = alturaNodo(hijo, A);
        int altMin = alturaNodo(hijo, A);
        if(A.hermDrcho(hijo)!=Agen<T>::NODO_NULO){
            typename Agen<T>::nodo hermDr = A.hermDrcho(hijo);
            while(hermDr != Agen<T>::NODO_NULO){
                altMax = std::max(altMax, alturaNodo(hermDr,A));
                altMin = std::min(altMin, alturaNodo(hermDr,A));
                hermDr = A.hermDrcho(hermDr);
            }
        }

        return altMax - altMin;
        
    }

}


template <typename T>
int alturaNodo(typename Agen<T>::nodo n, Agen<T>& A){
    if(n==Agen<T>::NODO_NULO){
        return 0;
    }else if(A.hijoIzqdo(n)==Agen<T>::NODO_NULO){
        return 0;
    }else{
        int aux = 0;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            aux = std::max(aux,alturaNodo(hijo,A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + aux;
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
   std::cout << desequilibrioAgen(A);
 //imprimirAgen(A); // En std::cout
} 
