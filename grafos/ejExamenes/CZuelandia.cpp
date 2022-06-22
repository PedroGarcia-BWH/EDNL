#include "../algoritmos/alggrafoPMC.h"
#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/grafoMA.h"
#include <cmath>
#include <iostream>

typedef double km;

matriz<typename GrafoP<double>::vertice> Czuelandia(typename GrafoP<double>::vertice capital,
    const GrafoP<double>& cuidades){
    typedef typename GrafoP<double>::vertice vertice;
    
    GrafoP<double> G(cuidades);

    for(vertice i=0; i<G.numVert(); i++){
        G[capital][i] = G[i][capital] = GrafoP<double>::INFINITO; // ponemos a infinito para poder ver los caminos resultantes
    }

    matriz<vertice> caminos;
    matriz<km> costes = Floyd(G, caminos);

    //nos queda que podemos ir directamente a la capital

    vector<vertice> P, Pinv;
    vector<km> costes = Dijkstra(cuidades,capital, P);
     vector<km> costesCapital = Dijkstra(cuidades,capital, Pinv);

     for(vertice i=0; i<G.numVert(); i++){ // guardamos los caminos directo en la matriz a devolver
       caminos[capital][i] = P[i];
       caminos[i][capital] = Pinv[i];

    }

    return caminos;
}