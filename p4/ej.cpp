

//ejercicio1 //hay que hacer un buscar pero sin devolver la referencia constante(igual pero quitar el const)
void eliminar(T elemento){
    arbol* subA = buscar_r(elemento);

    if(subA != nullptr){
            eliminar_R(subA);
    }
}

void eliminar_r(arbol* r){
    si(r!= nullptr){
        if(r->izdo != nullptr){
            eliminar_r(r->izdo);
        }
        if (r->der != nullptr){
            eliminar_r(r->der);
        }
        r = nullptr; // no hace falta poner a nullptr der y izdo  == muy pro da igual.
    }
}
//ej3

template <typename T>
using Conjunto = ABB<T> //si pones que deveulva un cojunto representado por un Abb esto hay que poner
//mñn no entra esto, como entre matamos a kevin SI


Conjunto A;
Conjunto B;
C =A;
if(!A.buscar(B.elto()))
    A.insertar(B.elto())
    equilibrar(C);

    //ej4
    //lo mismo pero 
    Conjunto A,B;
    C= A;
    si (!B.buscar(C.elto())){
        C.eliminar(C.elto())
    }

    //ej5
    //bool pertenece (T elto, Conjunto(A))
    return  A.buscar(elto);

    