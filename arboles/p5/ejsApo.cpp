#include <iostream>
#include "apo.h"

//PREGUNTAR A KEVIN EN EL 1 ME RELLA LO DE NO ESTAR ACOTADO PERO EN LOS APO TIENES QUE METER UN MAXNODOS
//ejercicio 1
template <typename T>
void eliminarElem(T elem, Apo<T>& A){
    Apo<T> B;
    eliminarElemRec(elem,A,B);
    A = B; //devolvemo el arbol que no tiene el elemento buscado

}
template <typename T>
void eliminarElemRec(T elem, Apo<T>& A, Apo<T>& B){
    if(!A.vacio()){
        if(A.cima() != elem) B.insertar(A.cima());
        A.suprimir();

        eliminarElemRec(elem,A,B);
    }
}