#include "abb.h"
#include "iostream"
using namespace std;
//EJERCICIO 2
template <typename T>
void equilibrar(Abb<T>& A){
    if(!A.vacio()){
         vector<T> elems;
        elementosInorden(elems,A.izqdo());
        elems.push_back(A.elemento());
        elementosInorden(elems,A.drcho()); 
        //guardarmos en el vector todos los elementos en inorden
        Abb<T> equilibrado;
        rellenarequilibrado(0,elems.size(),elems,equilibrado);
        A = equilibrado;
    }
   
}
template <typename T>
void elementosInorden(vector<T>& elems, const Abb<T>& Arbol){
     if(!A.vacio()){
        elementosInorden(elems,Arbol.izqdo());
        elems.push_back(A.elemento());
        elementosInorden(elems,Arbol.drcho());
    }
}

template <typename T>
void rellenarequilibrado(int inicio, int fin, vector<T> elems, Abb<T>& A){
    A.insertar(((inicio+fin)/2) + 1);
    rellenarequilibrado(inicio, ((inicio+fin)/2) + 1, elems,, A);
    rellenarequilibrado(((inicio+fin)/2) + 1, fin)
}

template <typename T>
using Conjunto = Abb<T>
//EJERCICIO 3
template <typename T>
const Abb<T>& unionConjunto(const Conjunto& A, const Conjunto& B){
    Conjunto C = A;

    unionConjuntoRec(B,C);

    return C;
}

template <typename T>
void unionConjuntoRec(const Conjunto& B,  const Conjunto& C ){
    Abb<T> aux = C.buscar(B.elemento());
    if(aux.vacio()){
        C.insertar(B.elemento());
    }
    unionConjuntoRec(B.izqdo(),C);
    unionCojuntoRec(B.drcho(),C);
}

//EJERCICIO 4
template <typename T>
using Conjunto = Abb<T>

template <typename T>
const Abb<T>& interseccion(const Conjunto& A, const Conjunto& B){
    Conjunto C = A;

    interseccionRec(B,C);

    return C;
}
///esta mal la intersecion terminarlo
template <typename T>
void interserccionRec(const Conjunto& B,  const Conjunto& C ){
    Abb<T> aux = C.buscar(B.elemento());
    if(aux.vacio()){
        C.eliminar(B.elemento());
    }else{
        
    }
    interserccionRec(B.izqdo(),C);
    interserccionRec(B.drcho(),C);
}

//PREGUNTAR A KEVIN SI TE PIDEN QUE UTILICES UN ABB EQUILIBRADO QUE QUE EXACTAMENTE HAY QUE HACER 