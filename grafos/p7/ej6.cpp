#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/matriz.h"
#include "../algoritmos/alggrafoPMC.h"
#include <vector>

using namespace std;


// aqui en vez de solo ser una ciudad es que sea varias ciudades que tengan transbordo
template <typename tCoste>
matriz<tCoste> tarifa(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus, const vector<typename GrafoP<tCoste::vertice>>& cuidadesTransbordo){
    
    typedef typename GrafoP<tCoste::vertice> vertice;
    GrafoP<tCoste> costesMin(tren.numVert()); // los dos grafos tienen los mismos vertices(cuidades)
    vector<vertice> P;
    matriz<tCoste> costeTren = Floyd(tren,P);
    matriz<tCoste> costeBus = Floyd(tren,P);

    for(auto it : cuidadesTransbordo){
       for(auto it2 : cuidadesTransbordo){
           if(costeTren[*it][*it2] <= costeBus[*it][*it2]) rellenarGrafo(*it, *it2, tren ,costesMin);
           else rellenarGrafo(it, it2, costesMin, bus);
       }
    }

     matriz<tCoste> costeTotal = Floyd(costesMin,P);

     return costeTotal;
}   

template <typename tCoste>
void rellenarGrafo(typename GrafoP<tCoste::vertice> origen,  typename GrafoP<tCoste::vertice> destino, const GrafoP<tCoste>& costes, GrafoP<tCoste>& costesMin){
    typedef typename GrafoP<tCoste::vertice> vertice;
    for(vertice i = origen ; i <= destino; i++){
        for(vertice j = origen ; j <= destino; j++){
            costesMin[i][j] = costes[i][j]; // mirar si tambien hay que hacer [j][i];
        }
    }
}

