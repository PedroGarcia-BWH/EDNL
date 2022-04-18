#include <iostream>
#include "abb.h"

//suponemos que el arbol nunca esta vacio
template <typename T>
T infimo(T x, const Abb<T>& A){
    return infimoRec(elem,A,A);
}
template <typename T>
T infimoRec(T elem, const Abb<T>& R, const Abb<T>& A){
    if(x < R.elemento()){
        return infimoRec(elem,exist, R.izqdo(),A);
    }else if (x == R.elemento()){
        Abb<T> aux = R.izqdo();
        if(!aux.vacio()){
            return aux.elemento();
        }else{
            return minimo(A);
        }
       
    }else{
        return infimoRec(elem,exist, R.drcho(),A);
    }
}

template <typename T>
T minimo(const Abb<T>& A){
    if(A.izqdo().vacio()){
        return A.elemento();
    }else{
        return minimo(A.izqdo());
    }
}

//suponemos que el arbol nunca esta vacio
template <typename T>
T supremo(T x, const Abb<T>& A){
    return supremoRec(elem,A,A);
}
template <typename T>
T supremoRec(T elem, const Abb<T>& R, const Abb<T>& A){
    if(x < R.elemento()){
        return infimoRec(elem,exist, R.izqdo(),A);
    }else if (x == R.elemento()){
        Abb<T> aux = R.drcho();
        if(!aux.vacio()){
            return aux.elemento();
        }else{
            return maximo(A);
        }
    }else{
        return infimoRec(elem,exist, R.drcho(),A);
    }
}

template <typename T>
T maximo(const Abb<T>& A){
    if(A.drcho().vacio()){
        return A.elemento();
    }else{
        return maximo(A.drcho());
    }
}
