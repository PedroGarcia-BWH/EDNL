#include <iostream>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"
//#include "AbinVectorial.h"
//#include "AbinRelativo.h"

template <typename T>
bool similares(const Abin<T>& A, const Abin<T>& B){
    return similaresRec(A.raiz(),B.raiz(),A,B);
}

template <typename T>
bool similaresRec(typename Abin<T>::nodo& nodoA, typename Abin<T>::nodo& nodoB, const Abin<T>& A,const Abin<T>& B){
    if(nodoA == Abin<T>::NODO_NULO && nodoB == Abin<T>::NODO_NULO){
        return true;
    }else if((nodoA != Abin<T>::NODO_NULO && nodoB == Abin<T>::NODO_NULO) || (nodoA == Abin<T>::NODO_NULO && nodoB != Abin<T>::NODO_NULO)){
        return false;
    }else if(nodoA != nodoB){
        return false;
    }else{
        return similaresRec(A.hijoIzqdo(nodoA), B.hijoIzqdo(nodoB),A,B) && similaresRec(A.hijoDrcho(nodoA), B.hijoDrcho(nodoB),A,B);
    }
}

template <typename T>
Abin<T> reflejado(const Abin<T>& B){
    Abin<T> Br;
    Br.insertarRaiz(B.elemento(B.raiz()));
    reflejadoRec(B.raiz(),Br.raiz(),B,Br);
    return Br;
}

template <typename T>
void reflejadoRec(typename Abin<T>::nodo& nodoB, typename Abin<T>::nodo& nodoBr, const Abin<T>& B, Abin<T>& Br){
    if(B.hijoDrcho(nodoB) != Abin<T>::NODO_NULO && B.hijoIzqdo(nodoB) != Abin<T>::NODO_NULO){
        Br.insertarHijoIzqdo(nodoBr, B.elemento(B.hijoDrcho(nodoB)));
        Br.insertarHijoDrcho(nodoBr, B.elemento(B.hijoIzqdo(nodoB)));

        reflejadoRec(B.hijoDrcho(nodoB),Br.hijoIzqdo(nodoBr),B,Br);
        reflejadoRec(B.hijoIzqdo(nodoB),Br.hijoDrcho(nodoBr),B,Br);

    }else if(B.hijoDrcho(nodoB) != Abin<T>::NODO_NULO){
        Br.insertarHijoIzqdo(nodoBr, B.elemento(B.hijoDrcho(nodoB)));
        reflejadoRec(B.hijoDrcho(nodoB),Br.hijoIzqdo(nodoBr),B,Br);

    }else if(B.hijoIzqdo(nodoB) != Abin<T>::NODO_NULO){
        Br.insertarHijoDrcho(nodoBr, B.elemento(B.hijoIzqdo(nodoB)));
        reflejadoRec(B.hijoIzqdo(nodoB),Br.hijoDrcho(nodoBr),B,Br);
    }
}

typedef struct{
    float operando;
    char operador;
}aritmetica;

aritmetica calculoAritmetico(const Abin<aritmetica>& A){
    
}

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.
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

