//suponemos que el arbol tiene minimo 1 nodo, ya que no tiene sentido que el arbol esté vacio

template <typename T>
typedef struct{
    T simbolo;
    char expresion;
}proposicion;

template <typename T>
T proposicion(const Abin<proposicion>& A){
    return proposicionRec(A.raiz(),A);
}

template <typename T>
T preposicionRec(typename Abin<proposicion>::nodo n, const Abin<proposicion> A){
    if(A.hijoIzdo(n) ==NODO_NULO){ //con que no exista el hijo izq nos vale ya que si existe es pq es proposicion, no ponemos el hijo derecho pq sino el not no se haria
        return A.elemento(n).simbolo;
    }else{
        switch(A.elemento(n).expresion){
            case '^': return preposicionesRec(A.hijoIzqdo(n),A) && preposicionesRec(A.hijoDrcho(n),A);
            case 'o': return preposicionesRec(A.hijoIzqdo(n),A) || preposicionesRec(A.hijoDrcho(n),A);
            case '-': return !preposicionesRec(A.hijoIzqdo(n),A)  // suponemos que siempre esta en el hijo izquierdo.
        }
    }
}