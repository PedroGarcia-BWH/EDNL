#include <iostream>
#include "abb.h"

//suponemos que el arbol nunca esta vacio
template <typename T>
T infimo(T x, const Abb<T>& A){
    T aux = A.elemento();
    infimoRec(aux, x,A);

    return aux;
}

template <typename T>
void infimoRec(T& aux,const T& x, const Abb<T>& A){

    if(!A.vacio()){

        if(x==A.elemento()){

            aux = A.elemento();

        }

        if(x<A.elemento()){
            if(A.izqdo().vacio()){
                aux = A.elemento();
            }else{
                infimoRec(aux,x,A.izqdo());
            }
            
        }

        if(x>A.elemento()){
            if(x==aux){
                aux=A.elemento();
            }else{
                aux = std::max(aux,A.elemento());
            }           
            infimoRec(aux,x,A.drcho());
        }

    }

}

//suponemos que el arbol nunca esta vacio
template <typename T>
T supremo(T x, const Abb<T>& A){
    T aux = A.elemento();
    supremoRec(aux, x,A);

    return aux;
}

template <typename T>
void supremoRec(T& aux,const T& x, const Abb<T>& A){

    if(!A.vacio()){

        if(x==A.elemento()){

            aux = A.elemento();

        }

        if(x<A.elemento()){
            aux = std::max(aux,A.elemento());
            supremoRec(aux,x,A.drcho());
          
            
        }

        if(x>A.elemento()){
            if(A.izqdo().vacio()){
                aux = A.elemento();
            }else{
                supremoRec(aux,x,A.izqdo());
            }
        }

    }

}


int main(){
    Abb<int> A;
    A.insertar(9);
    A.insertar(7);
    A.insertar(4);
    A.insertar(3);
    A.insertar(5);
    A.insertar(8);
    A.insertar(11);
     A.insertar(10);
    A.insertar(12);
    A.insertar(17);
    std::cout << infimo(14,A) <<std::endl;
     std::cout << infimo(2,A) <<std::endl;
}