#ifndef MIN_H
#define MAX_H
#include <cassert>
template <typename T> class Minmax{
    public:

    Minmax(size_t maxNodos);
    void insertar(const T& e);
    void suprimirMin();//elemento minimo
    void suprimirMax(); // elemento maximo
    const T& cima();
    bool vacio();

    Minmax(const Minmax<T>&);
    Minmax<T>& operator =(const Minmax<T>&);

    ~Minmax();

    private:
    typedef size_t nodo; // índice del vector
        // entre 0 y maxNodos-1
        T* nodos; // vector de nodos
        size_t maxNodos; // tamaño del vector
        size_t numNodos; // último nodo del árbol
        nodo abuelo(nodo i) const { return padre(padre(i)); }
        nodo padre(nodo i) const { return (i-1)/2; }
        nodo hIzq(nodo i) const { return 2*i+1; }
        nodo hDer(nodo i) const { return 2*i+2; }
        size_t profundidad(nodo i);
        void flotarPar(nodo i);
        void flotarImpar(nodo i);
        void hundirPar(nodo i);
        void hundirImpar(nodo i);
};

template <typename T>
Minmax<T>::Minmax(size_t maxNodos):maxNodos(maxNodos), numNodos(0), nodos( new T[maxNodos]){}

template <typename T>
bool Minmax<T>::vacio(){
    return numNodos == 0;
}

template <typename T>
const T& cima(){
    return nodos[0];
}

template <typename T>
void Minmax<T>::insertar(const T& e){
    assert(numNodos < maxNodos);
    
    nodos[numNodos]= e;

    numNodos++;
    if(numNodos > 1){
        if(profundidad(numNodos) % 2 == 0){
            flotarPar(numNodos);
        }else{
            flotarImpar(numNodos);
        }
    }

}

template <typename T>
size_t Minmax<T>::profundidad(nodo i){
    size_t prof = 0;
    while (i > 0){
        i = padre(i);
        prof++;
    }

    return prof;
}

//abuelo <= e <= padre
template <typename T> void Minmax<T>::flotarPar(nodo i)
{
    T e = nodos[i];
    while (i > 0 && nodos[abuelo(i)] <= e && e <= nodos[padre(i)])
    {
        nodos[i] = nodos[abuelo(i)];
        i = abuelo(i);
    }
    nodos[i] = e;
}

//padre <= e <= abuelo
template <typename T> void Minmax<T>::flotarImpar(nodo i)
{
    T e = nodos[i];
    while (i > 0 && nodos[padre(i)] <= e && e <= nodos[abuelo(i)])
    {
        nodos[i] = nodos[abuelo(i)];
        i = abuelo(i);
    }
    nodos[i] = e;
}

template <typename T>
Minmax<T>::~Minmax(){
    delete[] nodos;
}
#endif // minMax_H