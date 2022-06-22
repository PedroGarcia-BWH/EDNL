#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/matriz.h"
#include "../algoritmos/alggrafoPMC.h"


typedef int vertice;
typedef double km;

struct parte{
    vertice cliente;
    size_t cargas;
    parte(vertice cliente, size_t cargas): cliente(cliente), cargas(cargas) {}
};

//suponemos que el camion debe volver a la capital para cargar y para terminar el trabajo
template <typename tCoste>
km cementos(const GrafoP<km>& G, vertice capital, const vector<parte>& trabajo){
    vector<vertice> P;
    matriz<km> costes = Floyd(G,P);
    km distanciaTotal = 0;

    for(auto it : trabajo){
        distanciaTotal += costes[captial][it->cliente] * it->cargas; // sumamos la distancia hasta el cliente, multiplicamos por las cargas pq son las vueltas que debemos ir
        distanciaTotal += costes[it->cliente][capital] * it->cargas;

    }

    return km;

}

