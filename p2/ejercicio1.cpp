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
    if(nodoA == Abin<T>::NODO_NULO && nodoB == Abin<T>::NODO_NULO){ //como al entrar es nodo nulo los dos si es arbol vacio devuelve true(si este ejercicio como te da el caso base se puede hacer en la funcion principal y seria válido)
        return true;
    }else if((nodoA != Abin<T>::NODO_NULO && nodoB == Abin<T>::NODO_NULO) || (nodoA == Abin<T>::NODO_NULO && nodoB != Abin<T>::NODO_NULO)){ // mejor hacer (nodoA != NODO_NULO OR nodoB != NODO_NULO) , ya que si fuera los dos ya devuelve true asi que es mas aclaratorio
        return false;
    }else{
        return similaresRec(A.hijoIzqdo(nodoA), B.hijoIzqdo(nodoB),A,B) && similaresRec(A.hijoDrcho(nodoA), B.hijoDrcho(nodoB),A,B);
    }
}

template <typename T>
Abin<T> reflejado(const Abin<T>& B){
    Abin<T> Br;
    if(!B.arbolVacio()){
        Br.insertarRaiz(B.elemento(B.raiz()));
        reflejadoRec(Br, B.raiz(), Br.raiz(), B);
    }
    return Br;
}

template <typename T>
void reflejadoRec(Abin<T>& Br, typename Abin<T>::nodo& nodoB, typename Abin<T>::nodo& nodoBr, const Abin<T>& B){
    if(nodoB != Abin<T>::NODO_NULO){//esta comparacion se puede quitar pq nunca va a llegar a un nodo nulo
        if(B.hijoDrcho(nodoB) != Abin<T>::NODO_NULO && B.hijoIzqdo(nodoB) != Abin<T>::NODO_NULO){
            Br.insertarHijoIzqdo(nodoBr, B.elemento(B.hijoDrcho(nodoB)));
            Br.insertarHijoDrcho(nodoBr, B.elemento(B.hijoIzqdo(nodoB)));

            reflejadoRec(B.hijoDrcho(nodoB),Br.hijoIzqdo(nodoBr),B,Br);
            reflejadoRec(B.hijoIzqdo(nodoB),Br.hijoDrcho(nodoBr),B,Br);
        }else if(B.hijoDrcho(nodoB) == Abin<T>::NODO_NULO && B.hijoIzqdo(nodoB) != Abin<T>::NODO_NULO){
            Br.insertarHijoDrcho(nodoBr, B.elemento(B.hijoIzqdo(nodoB)));

            reflejadoRec(B.hijoIzqdo(nodoB),Br.hijoDrcho(nodoBr),B,Br);
        }else if(B.hijoDrcho(nodoB) != Abin<T>::NODO_NULO && B.hijoIzqdo(nodoB) == Abin<T>::NODO_NULO){
            Br.insertarHijoIzqdo(nodoBr, B.elemento(B.hijoDrcho(nodoB)));

            reflejadoRec(B.hijoDrcho(nodoB),Br.hijoIzqdo(nodoBr),B,Br);
        }
    }
}//este ejercicio se puede hacer con dos IFS HACER ESO EN EL EXAMEN EN VEZ DE IF-ELSE PQ ES MUHCO MAS LARGO Y NO TENER QUE HACER UN CASO GENERAL


//ej3
/*struct{
    char op;
    float dato;
}datos;
//como asumimos que el arbol esta correcto por tanto no esta vacio. pone que devolvamos un aritmetico no el tipo de elemento hecho
float calculo(Abin<datos> A){
    return calculoRec(A.raiz(),A);
}

float calculoRec(nodo n, Abin<datos> A){
    if(A.hijoIzdo(n) ==NODO_NULO && A.hijoDrcho(n) == NODO_NULO){
        devuelve A.elemento(n).dato;
    }else{
        switch(A.elemento(n).op){
            case '+': return calculoRec(A.hijoizq(n),A) + calculoRec(A.hijoder(n),A); //terminar
                    break;//no haria falta ya que tiene el return;
        }
    }
}
*/
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

