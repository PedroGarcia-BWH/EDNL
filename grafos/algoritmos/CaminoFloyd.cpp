#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/grafoMA.h"
#include "../algoritmos/matriz.h"

template <typename tCoste>
vector<typename GrafoP<tCoste>::vertice> camino(const matriz<typename GrafoP<tCoste>::vertice>& P, typename GrafoP<tCoste>::vertice origen,
typename GrafoP<tCoste>::vertice destino){
    typedef GrafoP<tCoste>::vertice vertice;
    vector<vertice> caminito = caminoAux<tCoste>(P, origen, destino);
    caminito.insert(origen, caminito.begin());
    caminito.insert(destino, caminito.end());

    return caminito;
}

template <typename tCoste>
vector<typename GrafoP<tCoste>::vertice> caminoAux(const matriz<typename GrafoP<tCoste>::vertice>& P, typename GrafoP<tCoste>::vertice origen,
typename GrafoP<tCoste>::vertice destino){
    typedef GrafoP<tCoste>::vertice vertice;
    vector<vertice> C1,C2;
    vertice u = P[origen][destino];

    if( u != origen){
         C1 = caminoAux(P,origen, u);
        C1.push_back(u);
        C2 = caminoAux(P,u, destino);
        C1 += C2;// haria falta hacer una concatenacion aqui
    }
   

    return C1;
}