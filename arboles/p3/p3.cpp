


int nGrado(Agen A){ //al ser -1 cuando el arbol está vacio ya que no tiene sentido que devuelva 0, si es solo la raiz es 0 el grado
    if (A.arbolVacio())
    {
        return -1;
    }else{
          return nGradoRec(A.raiz(),A);
    } 
}

int nGradoRec(nodo n, Agen A){
    if(n == NODO_NULO){
        return 0;
    }else{
        int gradoAux;
        int gradoMax = gradoNodo(n,A);
        nodo aux = A.hijoIzq(n);
        while(aux != NODO_NULO){
            gradoAux = gradoRec(aux,A);
            aux = hermDrcho(aux);
            gradoMax = std::max(gradoMax,gradoAux);
        }
        return gradoMax;
    }
}

//funcion auxiliar


int gradoNodo(nodo n, Agen A){
    int grado = 0;
    nodo aux = A.hijoIzq(n);

    while(aux != NODO_NULO){
        grado++;
        aux = A.hermDrcho(aux);
    }

    return grado; 
}

int profundidadAgen(nodo n,Agen A){
    if(n == NODO_NULO){
        return -1;
    }else{
        return 1+A.padre(n);

    }
}

Agen poda(Agen A, nodo n){
    Agen B;
    if(!A.arbolVacio()){
        podaRec(A.raiz(),B.raiz(),n,A,B);
    }
    return B;
    
}
//ej3: necesitmaos dos funciones ,altura max y alturamin(profundidad)

/*
    max = AlturaArbol(A)
    min = profMInHojas(A)
    devuelvo max-min;
*/
void podaRec(nodo nA, nodo nB, nodo n, Agen A, Agen& B){
    if(nA != NODO_NULO){
        if(nA != n){
            A.insertarhijoIzq()
            nodo aux  =A.hijoizq(n);


        }
    }
}

//ej4
/* cuando pone poda es eliminar en ese mismo arboo no en otro nuevo, auqn kevin dice el no lo pondria mal.
nodo buscar(int elto,nodo n,Agen A){
    nodo aux = NODO_NULO;
    si(A.elemento(n) != elto) aux = n
    return aux;
}