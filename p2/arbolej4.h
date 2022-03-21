#ifndef ARBOLEJ4_H
#define ARBOLEJ4_H

#include <cassert>
using namespace std;

template <typename T> class Abin{
    public: 
        typedef size_t nodo;
        static const nodo NODO_NULO;
        Abin(size_t maxAltura, const T& e_nulo = T());
        void insertarRaiz(const T& elem);
        void insertarHijoIzqdo(nodo n, const T& e);
        void insertarHijoDrcho(nodo n, const T& e);
        void eliminarRaiz();
        void eliminarHijoIzqdo(nodo n);
        void eliminarHijoDrcho(nodo n);
        nodo hijoIzqdo(nodo n) const ;
        nodo hijoDrcho(nodo n) const ;
        nodo padre(nodo n)  ;
        nodo raiz() const;
        bool arbolVacio() const;
        ~Abin();
        const T& elemento(nodo n) const ;
        T& elemento(nodo n);
    private:
        size_t maxAltura;
        size_t maxNodos;
        T elto_nulo;
        T* nodos;
        int altura(nodo n);
};
template <typename T>
    const typename Abin<T>::nodo Abin<T>::NODO_NULO(SIZE_MAX);

template <typename T>
Abin<T>::Abin(std::size_t maxAltura, const T& e_nulo): maxNodos(std::pow(2,maxAltura+1)-1),nodos(new T[maxNodos]), elto_nulo(e_nulo), maxAltura(maxAltura){
    for(size_t i =0; i<maxNodos;i++;){
        nodos[i] = elto_nulo;
    }

}

template <typename T>
void Abin<T>::insertarRaiz(const T& elem){
    nodos[maxNodos/2]  = elem;
}

template<typename T>
void Abin<T>::insertarHijoIzqdo(nodo n, const T& e){
    nodos[n-pow(2,altura(n)-1)] = e;
} 

template <typename T>
Abin<T>::nodo Abin<T>::padre(nodo n){
    if(n < maxNodos/2) return n+ pow(2,alturaMax(n));
    else return n - pow(2,altura(n));
}

template <typename T>
int Abin<T>::altura(nodo n){
    bool terminado = false;
    int rangoMin = 0;
    int rangoMax = maxNodos;
    int altura = 0;
    while(!terminado) {
        if(n > rangoMax/2){
            rangoMin = rangoMax/2;

        }else{
            rangoMax = rangoMax /2;
        }

        if(n == rangoMax/2) terminado = true;
        altura++,
    }

    return altura;
}
#endif