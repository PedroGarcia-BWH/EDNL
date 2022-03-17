#include <iostream>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"
//#include "AbinVectorial.h"
//#include "AbinRelativo.h"

template <typename T>
int nodosVerdes(const Abin<T>& A){
    return nodosVerdesRec(A.raiz(),A);
}
template <typename T>
int nodosVerdesRec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 0; 
    }else{
        typename Abin<T>::nodo hizq = A.hijoIzqdo(n);
        typename Abin<T>::nodo hder = A.hijoDrcho(n);
        if(( hizq != Abin<T>::NODO_NULO && hder != Abin<T>::NODO_NULO) && 
        ((A.hijoIzqdo(hizq) != Abin<T>::NODO_NULO && A.hijoDrcho(hizq) != Abin<T>::NODO_NULO && A.hijoIzqdo(hder) != Abin<T>::NODO_NULO && A.hijoDrcho(hder) == Abin<T>::NODO_NULO) ||
        (A.hijoIzqdo(hizq) != Abin<T>::NODO_NULO && A.hijoDrcho(hizq) != Abin<T>::NODO_NULO && A.hijoIzqdo(hder) == Abin<T>::NODO_NULO && A.hijoDrcho(hder) != Abin<T>::NODO_NULO) ||
        (A.hijoIzqdo(hizq) != Abin<T>::NODO_NULO && A.hijoDrcho(hizq) == Abin<T>::NODO_NULO && A.hijoIzqdo(hder) != Abin<T>::NODO_NULO && A.hijoDrcho(hder) != Abin<T>::NODO_NULO) ||
        (A.hijoIzqdo(hizq) == Abin<T>::NODO_NULO && A.hijoDrcho(hizq) != Abin<T>::NODO_NULO && A.hijoIzqdo(hder) != Abin<T>::NODO_NULO && A.hijoDrcho(hder) != Abin<T>::NODO_NULO) )){
            
            return 1 + nodosVerdesRec(A.hijoIzqdo(n),A) + nodosVerdesRec(A.hijoDrcho(n),A);
        }else{
            return nodosVerdesRec(A.hijoIzqdo(n),A) + nodosVerdesRec(A.hijoDrcho(n),A);
        }
    }
}


/*int nodosVerdes2(const Abin<std::string>& A){
    return nodosVerdesRec2(A.raiz(),A);
}

int nodosVerdesRec2(typename Abin<std::string>::nodo n, const Abin<std::string>& A){
    std::string a = "verde";
    if(n == Abin<std::string>::NODO_NULO){
        return 0;
    }else if(A.elemento(n) == a){ // comprobar si metiendo "verde" tambien funciona
        return 1 + nodosVerdesRec2(A.hijoIzqdo(n),A) + nodosVerdesRec2(A.hijoDrcho(n),A);
    }else{
        return nodosVerdesRec2(A.hijoIzqdo(n),A) + nodosVerdesRec2(A.hijoDrcho(n),A);
    }
}*/

template <typename T>
Abin<T> poda( const typename Abin<T>::nodo& n, const Abin<T>& A){
    Abin<T> B;
    if (n != A.raiz()){
        B.insertarRaiz(A.elemento(A.raiz())); // como debemos encontrar n minimo tendrá siempre n; suponemos que no metemos n 
        podaRec(A.raiz(), B.raiz(), n, A, B);
    }
    return B;
}
//suponemos que no metemos el nodo en la poda asi que eliminamos a partir de ese nodo //HACER ESTE EJERCICIO HACIENDO LA PODA AL MISMO ARBOL
//Preguntar a kevin si nos pide q devolvamos al mismo nodo si creamos un arbol auxiliar y luego igualos A= B;
template <typename T>
void podaRec(typename Abin<T>::nodo nA, typename Abin<T>::nodo nB,  const typename  Abin<T>::nodo& n, const Abin<T>& A, Abin<T>& B){
    if(A.hijoIzqdo(nA) != Abin<T>::NODO_NULO){
        if(nA != n){
            B.insertarHijoIzqdo(nB, A.elemento(A.hijoIzqdo(nA)));
            podaRec(A.hijoIzqdo(nA),A.hijoIzqdo(nB),n,A,B);
        }
    }
    if(A.hijoDrcho(nA) != Abin<T>::NODO_NULO){
         if(nA != n){
            B.insertarHijoDrcho(nB, A.elemento(A.hijoDrcho(nA)));
            podaRec(A.hijoDrcho(nA),A.hijoDrcho(nB),n,A,B);
        }
    }
}
 
template <typename T>
Abin<T> multiplica(const Abin<T>& A, const T& num){
    Abin<T> B;
    if(!A.arbolVacio()){
        B.insertarRaiz(A.elemento(A.raiz()) * num );
        multiplicaRec(A.raiz(),B.raiz(),num,A,B);
    }
    return B; 
}


template<typename T>
void multiplicaRec(typename Abin<T>::nodo nA, typename Abin<T>::nodo nB, const T& num, const Abin<T>& A,  Abin<T>& B){
    if(A.hijoIzqdo(nA) != Abin<T>::NODO_NULO){
        B.insertarHijoIzqdo(nB, A.elemento(A.hijoIzqdo(nA)) * num);
        multiplicaRec(A.hijoIzqdo(nA),A.hijoIzqdo(nB),num,A,B);
    }
    if(A.hijoDrcho(nA) != Abin<T>::NODO_NULO){
        B.insertarHijoDrcho(nB, A.elemento(A.hijoDrcho(nA)) * num);
        multiplicaRec(A.hijoDrcho(nA),A.hijoDrcho(nB),num,A,B);
    }
}

template <typename T>
int sucesores(typename Abin<T>::nodo n, Abin<T> A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        return 1 + sucesores(A.hijoIzqdo(n),A) + sucesores(A.hijoDrcho(n),A);
    }
}

template <typename T>
int antecesores(typename Abin<T>::nodo n, Abin<T> A){
    if (n == Abin<T>::NODO_NULO){
        return -1;
    }else{
        return 1 + antecesores(A.padre(n),A);
    }
}


template<typename T>
int masSucesores(const Abin<T>& A){
    return masSucesoresRec(A.raiz(),A);
}

template <typename T>
int masSucesoresRec(typename Abin<T>::nodo n, Abin<T> A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else if(sucesores(n,A) > antecesores(n,A)){
        return 1 + masSucesoresRec(A.hijoIzqdo(n),A) + masSucesoresRec(A.hijoDrcho(n),A);
    }else{
        return masSucesoresRec(A.hijoIzqdo(n),A) + masSucesoresRec(A.hijoDrcho(n),A);
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

 //cout << "Nodos verdes: " << nodosVerdes(A);
 /*Abin<tElto> C = multiplica(A,10);
 cout << "Multiplica" <<endl;
 imprimirAbin(C); // En std::cout*/

//cout<<masSucesores(A);

    cout << "Nodos verdes: " << nodosVerdes(A);
 Abin<tElto> C = poda(A.hijoIzqdo(A.raiz()),A);
 cout << "Multiplica" <<endl;
 imprimirAbin(C); // En std::cout

 
} 

