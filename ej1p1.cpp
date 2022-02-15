#include <iostream>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

template <typename T>
int nNodos(Abin<T> arbol){
    return nNodos_Rec(arbol,arbol.raiz());
}
template <typename T>
int nNodos_Rec(Abin<T> arbol, typename  Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
    }else{
        return 1+ nNodos_Rec(arbol, arbol.hijoIzqdo(n)) + nNodos_Rec(arbol, arbol.hijoDrcho(n));   
    }
  

}

template <typename T>
int alturaArbol(Abin<T> arbol){
    return alturaArbol_rec(arbol,arbol.raiz());
}

template <typename T>
int alturaArbol_rec(Abin<T> arbol, typename Abin<T>::nodo n){
    int ramaA = 0, ramaB=0;
    if (n == Abin<T>::NODO_NULO){
        return -1;
    }else{
        ramaA= 1+ alturaArbol_rec(arbol,arbol.hijoIzqdo(n));
        ramaB= 1 + alturaArbol_rec(arbol,arbol.hijoDrcho(n));

        return(ramaA > ramaB) ? ramaA : ramaB;
    }
}
//Precondicion: el nodo debe estar en el arbol
template <typename T>
int profundidadNodo(Abin<T> A, typename Abin<T>::nodo n){
    return profundidadNodo_rec(A,A.raiz(),n);
}
template <typename T>
int profundidadNodo_rec(Abin<T> A, typename Abin<T>::nodo i, typename Abin<T>::nodo n)
{
    int ramaA = 0, ramaB=0;
    if(i == Abin<T>::NODO_NULO){
        return -500;
    }else if(i== n){
        return -1;
    }else{
        ramaA= 1+ alturaArbol_rec(A,A.hijoIzqdo(n));
        ramaB= 1 + alturaArbol_rec(A,A.hijoDrcho(n));

        return(ramaA > ramaB) ? ramaA : ramaB;
    }
}

carlos es gay


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

 //cout << "Nnodos : " << nNodos(A)<< endl;

//cout << "Altura: " <<alturaArbol(A);
cout<<"Profundidad: " << profundidadNodo(A, A.raiz());
} 

