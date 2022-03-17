


int nGrado(Agen A){
    return nGradoRec(A.raiz(),A);
}

int nGradoRec(nodo n, Agen A){
    if(n == NODO_NULO){
        return 0;
    }else{
        nodo aux = A.hijoIzq(n);
        int hijos = 0;
        while(aux != NODO_NULO){
            if(hijos == 0) hijos  = 2;
            hijos++;
            aux = A.hermDrcho(n);
        }

        while(aux != NODO_NULO){
            
        }
    }
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

void podaRec(nodo nA, nodo nB, nodo n, Agen A, Agen& B){
    if(nA != NODO_NULO){
        if(nA != n){
            A.insertarhijoIzq()
            nodo aux  =A.hijoizq(n);


        }
    }
}