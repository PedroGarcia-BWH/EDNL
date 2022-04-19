#include <iostream>
#include "abb.h"

//suponemos que el arbol nunca esta vacio
template <typename T>
T infimo(T x, const Abb<T>& A){
    return infimoRec(x,A,A);
}

template <typename T>
T infimoRec(T x, const Abb<T>& R, const Abb<T>& A){
    if(x < R.elemento()){
        return infimoRec(x, R.izqdo(),A);
    }else if (x == R.elemento()){
        Abb<T> aux = R.izqdo();
        if(!aux.vacio()){
            return aux.elemento();
        }else{
            return minimo(A);
        }
       
    }else{
        return infimoRec(x, R.drcho(),A);
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
    return supremoRec(x,A,A);
}
template <typename T>
T supremoRec(T x, const Abb<T>& R, const Abb<T>& A){
    if(x < R.elemento()){
        return supremoRec(x, R.izqdo(),A);
    }else if (x == R.elemento()){
        Abb<T> aux = R.drcho();
        if(!aux.vacio()){
            return aux.elemento();
        }else{
            return maximo(A);
        }
    }else{
        return supremoRec(x, R.drcho(),A);
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


int main(){
    Abb<int> A;
    A.insertar(10);
    A.insertar(8);
    A.insertar(15);
    A.insertar(7);
    A.insertar(9);
    std::cout << infimo(7,A) <<std::endl;
    std::cout << supremo(7,A) <<std::endl;
}