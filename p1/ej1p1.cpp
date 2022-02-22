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
    return profundidadNodo_rec(A,n);
}
template <typename T>
int profundidadNodo_rec(Abin<T> A,  typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO){ //pewguntar porque no funciona si ponemos que n sea igual que nodo raiz
        return -1;
    }else{
        return 1 + profundidadNodo_rec(A,A.padre(n));
    }
}
template <typename T>
int desequilibrio (Abin<T> A){
    return desequilibrio_rec(A,A.raiz(),0);
}

//template<typename T>
/*int desequilibrio_rec(Abin<T> A, typename Abin<T>::nodo n, int &maximo){
    if (n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        int alturaN = altura_rec(A,n);
        if(alturaN > maximo) maximo = alturaN;

        return 
    }

}*/


template <typename T>
bool pseudocompleto (Abin<T> A){
    return pseudocompleto_rec(A, A.raiz(), alturaArbol(A),0);
}
template <typename T>
bool pseudocompleto_rec(Abin<T> A, typename Abin<T>::nodo n, int alturaNivel, int alturaActual){
    if(n == Abin<T>::NODO_NULO){
        return true;
       
    }else if(alturaNivel - 1  == alturaActual){
        if((A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO) || (A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO))
        {
            return true;
        }else{
            return false;
        }
    }else{
        return pseudocompleto_rec(A,A.hijoIzqdo(n),alturaNivel,alturaActual+1) && pseudocompleto_rec(A,A.hijoDrcho(n),alturaNivel,alturaActual+1);
    }
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

 //cout << "Nnodos : " << nNodos(A)<< endl;

//cout << "Altura: " <<alturaArbol(A);
//cout<<"Profundidad: " << profundidadNodo(A, A.raiz());

cout << "Pseudocompleto " <<  pseudocompleto(A);
} 

