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
Abin<T> poda(const typename Abin<T>::nodo& n, Abin<T>& A){
    podaRec(n,n,A); //no hace falta recorrer el arbol ya que tenemos el nodo, si tuvieramos el elemento si tendriamos que encontrar el nodo que contiene ese elemento
    return A;
}
//suponemos que n no puede ser podado
template <typename T>
void podaRec(const typename Abin<T>::nodo& nActual,  const typename Abin<T>::nodo& n, Abin<T>& A){ //pasamos el nodo como referencia ya que si es por valor la direccion de memoria es diferente y no son iguales
    if(A.hijoIzqdo(nActual) == Abin<T>::NODO_NULO && A.hijoDrcho(nActual) == Abin<T>::NODO_NULO && nActual != n){ //si por casualidad n es nodo hoja no lo podamos
        if(nActual == A.hijoIzqdo(A.padre(nActual))) A.eliminarHijoIzqdo(A.padre(nActual));
        else A.eliminarHijoDrcho(A.padre(nActual));
    }else{
        podaRec(A.hijoIzqdo(nActual),n,A);
        podaRec(A.hijoDrcho(nActual),n,A);

        if(nActual != n){ //cuando lleguemos a la primera llamada para que no pode n que sea distino al nodoActual, aunque sepamos que seria la primera llamada 
            if(nActual == A.hijoIzqdo(A.padre(nActual))) A.eliminarHijoIzqdo(A.padre(nActual));
            else A.eliminarHijoDrcho(A.padre(nActual));
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
    }else if(sucesores(n,A)-1 > antecesores(n,A)){
        return 1 + masSucesoresRec(A.hijoIzqdo(n),A) + masSucesoresRec(A.hijoDrcho(n),A); // ya que metemos el nodo como sucesor y no puede ser, en la profundidad al poner -1 ya hemos quitado ese nodo
    }else{
        return masSucesoresRec(A.hijoIzqdo(n),A) + masSucesoresRec(A.hijoDrcho(n),A);
    }

}

//reflejar nodo que tiene solo 1 hijo
template <typename T>
Abin<T> ArbolReflejado(const Abin<T>& A){
    Abin<T> B;
    if(!A.arbolVacio()){
        B.insertarRaiz(A.elemento(A.raiz()));
        ArbolReflejadoRec(A.raiz(),B.raiz(),B,A);
    }

    return B;
}

template <typename T>
void ArbolReflejadoRec(typename Abin<T>::nodo nA , typename Abin<T>::nodo nB, Abin<T> B, const Abin<T>& A){
    if(nA != Abin<T>::NODO_NULO){
        if((A.hijoIzqdo(nA) != Abin<T>::NODO_NULO && A.hijoDrcho(nA) == Abin<T>::NODO_NULO) || 
        (A.hijoIzqdo(nA) == Abin<T>::NODO_NULO && A.hijoDrcho(nA) != Abin<T>::NODO_NULO))
        {
            if(A.hijoIzqdo(nA) != Abin<T>::NODO_NULO){
                B.insertarHijoDrcho(nB,A.elemento(A.hijoIzqdo(nA)));
                
                ArbolReflejadoRec(A.hijoIzqdo(nA),B.hijoDrcho(nB),B,A);
            }else{
                B.insertarHijoIzqdo(nB,A.elemento(A.hijoDrcho(nA)));
                
                ArbolReflejadoRec(A.hijoDrcho(nA),B.hijoIzqdo(nB),B,A);
            }
        }else
        {
            if(A.hijoIzqdo(nA) != Abin<T>::NODO_NULO){
                B.insertarHijoIzqdo(nB,A.elemento(A.hijoIzqdo(nA)));
                
                ArbolReflejadoRec(A.hijoIzqdo(nA),B.hijoIzqdo(nB),B,A);
            }
            if(A.hijoDrcho(nA) != Abin<T>::NODO_NULO){
                B.insertarHijoDrcho(nB,A.elemento(A.hijoDrcho(nA)));
                
                ArbolReflejadoRec(A.hijoDrcho(nA),B.hijoDrcho(nB),B,A);
            }
        }
    }
}

//Poda desde un elemento del arbol
template <typename T>
void poda(T elem, Abin<T>& A){
    podaRec(A.raiz(),elem,A);
}

template <typename T>
void podaRec(typename Abin<T>::nodo n, T elem, Abin<T>& A){

    if(n != Abin<T>::NODO_NULO)
    {
        if(A.elemento(n) == elem)
        {
            podaNodos(A.hijoIzqdo(n),A); //preguntar a kevin si es mejor tener dos funciones y asi no llamamos al nodo o comprobarlo en la funcion de podaNodos pa q no pode ese nodo
            podaNodos(A.hijoDrcho(n),A);// preguntar si los prototipos lo ponemos en  c++ o los de la especififacion y si tenemos que utilizar el constructor cual ponemos
        }else{
            podaRec(A.hijoIzqdo(n),elem,A);
            podaRec(A.hijoDrcho(n),elem,A);
        }
    }
}

//hundar un nodo //te quedas con el izquierdo a menos que te den una prioridad



//como suponemos que no debemos podar el nodo que nos pide entonces si n(nodo por el cual se pueda podar) es raiz no pasaria nada, si tuvieramos que eliminar incluyendo el nodo deberiamos comprobar q no es raiz 
template <typename T>
void podaNodos(typename Abin<T>::nodo n, Abin<T>& A){
    if(n != Abin<T>::NODO_NULO)
    {
        podaNodos(A.hijoIzqdo(n),A);
        podaNodos(A.hijoDrcho(n),A);

        if(A.hijoIzqdo(A.padre(n)) == n){
            A.eliminarHijoIzqdo(A.padre(n));
        }else{
            A.eliminarHijoDrcho(A.padre(n));
        }
    }
}
template <typename T>
int alturaRec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }else{
        return 1 + std::max(alturaRec(A.hijoIzqdo(n),A),alturaRec(A.hijoDrcho(n),A));
    }
}

template <typename T>
int altura(const Abin<T>& A){
    return alturaRec(A.raiz(),A);
}

template <typename T>
int nNodosNivel(const Abin<T> A){
    return nNodosNivelRec(A.raiz(),A);
}

template <typename T>
int nNodosNivelRec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n != Abin<T>::NODO_NULO){
        return 0;
    }else{
        if(NodosNivel(n,profundidad(n,A),A)-1 == 2)
        {
            return 1 + nNodosNivelRec(A.hijoIzqdo(n),A) + nNodosNivelRec(A.hijoDrcho(n),A);    
        }else{
            return nNodosNivelRec(A.hijoIzqdo(n),A) + nNodosNivelRec(A.hijoDrcho(n),A); 
        }
    }
}

template <typename T>
int NodosNivel(typename Abin<T>::nodo n, int profNodo, const Abin<T>& A){
    if(n != Abin<T>::NODO_NULO){
        return 0;
    }else{
        if(profundidad(n,A) == profNodo)
        {
            return 1;    
        }else{
            return NodosNivel(A.hijoIzqdo(n), profNodo,A) + NodosNivel(A.hijoDrcho(n),profNodo,A);
        }
    }
}


template <typename T>
int profundidad (typename Abin<T>::nodo n, const Abin<T>& A){
    if(n != Abin<T>::NODO_NULO){
        return -1;
    }else{
        return 1 + profundidad(A.padre(n));
    }
}
template <typename T>
void hundir(const T& elem, Abin<T>& A){
    hundirNodoRec(A.raiz(),elem,A);
}
template <typename T>
void hundirRec(typename Abin<T>::nodo n, const T& elem, Abin<T>& A){
    if(n != Abin<T>::NODO_NULO){
        if(A.elemento(n) == elem){
            hundirNodo(n,A);
        }else{
            hundirRec(A.hijoIzqdo(n),A);
            hundirRec(A.hijoDrcho(n),A);
        }
    }
}

template <typename T>
void hundirNodo(typename Abin<T>::nodo n, const T& elem,  Abin<T>& A){
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO){
        T swap = A.elemento(n);
        A.elemento(n) = A.elemento(A.hijoIzqdo(n));
        A.elemento(A.hijoIzqdo(n) = swap;
        hundirNodo(A.hijoIzqdo(n),A);
    }else if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO){
        T swap = A.elemento(n);
        A.elemento(n) = A.elemento(A.hijoDrcho(n));
        A.elemento(A.hijoDrcho(n) = swap;
        hundirNodo(A.hijoDrcho(n),A);
    }
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.elemento(n) == elem ){
        if(A.padre(n) == Abin<T>::NODO_NULO){
            A.eliminarRaiz();
        }
        if(A.hijoIzqdo(A.padre(n)) == n){
            A.eliminarHijoIzqdo(A.padre(n);
        }
        if(A.hijoIzqdo(A.padre(n)) == n){
            A.eliminarHijoDrcho(A.padre(n);
        }
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

    /*cout << "Nodos verdes: " << nodosVerdes(A);
 Abin<tElto> C = poda(A.hijoIzqdo(A.raiz()),A);
 cout << "Multiplica" <<endl;
 imprimirAbin(C); // En std::cout*/



//A = poda(A.hijoIzqdo(A.raiz()),A);
    //A = ArbolReflejado(A);

 cout << "Altura: " << altura(A);
 imprimirAbin(A); // En std::cout
 A.~Abin();
  imprimirAbin(A); // En std::cout
} 

