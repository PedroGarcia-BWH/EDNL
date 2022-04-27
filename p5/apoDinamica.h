#ifndef APO_H
#define APO_H
#include <cassert>

template <typename T>class Apo{
  public:
    Apo();
    void suprimir();
    const T& cima();
    void insertar(const T& e);
    bool vacio();
    Apo<T>& operator =(const Apo<T>&);
    Apo(const Apo<T>&);
    ~Apo();
  private:  
    static const nodo NODO_NULO;
    typedef celda* nodo;
    typedef struct{
        nodo padre,hizq,hder;
        T elem;
        celda(const T& e, nodo p = NODO_NULO): elem(e),
            padre(p), hizq(NODO_NULO), hder(NODO_NULO){}
    }celda;
    nodo raiz = NODO_NULO, ultimoAñadido = NODO_NULO;
    void hundir(nodo n);
    void flotar(nodo n);
    //buscarUltimoNodo
};

template <typename T>
const typename Apo<T>::nodo Apo<T>::NODO_NULO(nullptr);

template <typename T>
Apo<T>::Apo(): r(NODO_NULO){}

template <typename T>
const T& Apo<T>::cima(){
    return r->elem;
}

template <typename T>
bool Apo<T>::vacio(){
    return r == NODO_NULO;
}

template <typename T>
void Apo<T>::insertar(const T& e){
    nodo nuevo = new nodo(e);
    if(r == NODO_NULO){
        r = new nodo(e);
        ultimoAñadido = r;
    }else{
        nodo padreUltimo = buscarPadreUltimo();
        if(padreUltimo->hizq == NODO_NULO){
            padreUltimo->hizq = nuevo;
            nuevo->padre = padreUltimo;
        }else{
            padreUltimo->hder = nuevo;
            nuevo->padre = padreUltimo;
        }

        flotar(nuevo);
    }
}

template <typename T>
void Apo<T>::suprimir(){
    assert(r == NODO_NULO);
    r->elem = ultimo->elem;
    delete ultimo;
    ultimo = elegirUltimo();
    
    hundir(r);
}
template <typename T>
void Apo<T>::hundir(nodo n){
    bool fin = false;
    T e = n->elem;
    while(n->hizq != NODO_NULO && !fin){
        nodo hMin;
        if(n->hder != NODO_NULO && n->hder < n->hder ){
            hMin = n->hder;
        }else{
            hMin = n->hizq
        }

        if(hMin->elem < e){
            n->elem = hMin->elem;
            n = hMin;
        }else{
            fin = true;
        }
    }
    n->elem = e;
}

template <typename T>
void Apo<T>::flotar(nodo n){
    T e = n->elem;
    while(n->padre != NODO_NULO && e < n->padre){
        n->elem = n->padre->elem;
        n = n->padre;
    }
    n->elem = e;
}

template <typename T>
Apo<T>::~Apo(){

}
#endif // APO_H