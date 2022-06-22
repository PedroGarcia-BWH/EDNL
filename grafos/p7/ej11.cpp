#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/matriz.h"
#include "../algoritmos/alggrafoPMC.h"
#include <vector>
using namespace std;

template <typename tCoste>
struct puente{
    size_t n1, n2;
    tCoste coste;
};

template <typename tCoste>
tCoste zuelandia(const matriz<tCoste>& isla1, const matriz<tCoste>& isla2, const matriz<tCoste>& isla3, const vector<puente<tCoste>>& puentes){
    typedef typename GrafoP<tCoste>::vertice vertice;

    GrafoP<tCoste> G(isla1.dimension()+isla2.dimension()+isla3.dimension());

    for(vertice i= 0; i < G.numVert(); i++){
        for(vertice j=0; j <G.numVert(); j++){
            G[i][j] =  typename Grafo<tCoste>::INFINITO; // lo ponemos infinito y luego le damos los valores
        }
    }

    for(vertice i= 0; i < isla1.dimension(); i++){
        for(vertice j=0; j < isla1.dimension(); j++){
            G[i][j] =  isla1[i][j];
        }
    }

    for(vertice i= isla1.dimension(); i< isla1.dimension() + isla2.dimension(); i++){
        for(vertice j=isla1.dimension(); j< isla1.dimension() + isla2.dimension(); j++){
            G[i][j] =  isla2[i][j];
        }
    }

    for(vertice i= isla1.dimension() + isla2.dimension(); i< isla1.dimension() + isla2.dimension() + isla3.dimension(); i++){
        for(vertice j= isla1.dimension() + isla2.dimension(); j< isla1.dimension() + isla2.dimension() + isla3.dimension(); j++){
            G[i][j] =  isla3[i][j];
        }
    }

    for(int i=0; i < puentes.size(); i++){
        G[puentes[i].n1][puentes[i].n2] = G[puentes[i].n2][puentes[i].n1] = puentes[i].coste;
    }
    vector<vertice> P;
    matriz<tCoste> costes = Floyd(G, P);

    return costes;
}