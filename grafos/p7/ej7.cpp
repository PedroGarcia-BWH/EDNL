#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/matriz.h"
#include "../algoritmos/alggrafoPMC.h"
#include <vector>

template <typename tCoste>struct costes{
    tCoste costeTotal;
    vector<typename GrafoP<tCoste>::vertice> camino;
    costes(tCoste costeTotal, const vector<typename GrafoP<tCoste>::vertice>& camino): costeTotal(costeTotal), camino(camino) {}
};

template <typename tCoste>
costes<tCoste> buscarCamino(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus,
typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino, 
typename GrafoP<tCoste>::vertice cambio1, typename GrafoP<tCoste>::vertice cambio2){

    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> costesMin(tren.numVert());
    vector<vertice> P;
    vector<tCoste> costeTren, costeBus, costeTotal;
    rellenarGrafo(origen, cambio1, tren, costesMin); // metemos el coste desde el tren ya que empezamos desde ahi y no podemos cambiarlo
    costeTren = Dijkstra(tren, cambio1, P);
    costeBus = Dijkstra(bus, cambio1, P);

    if(costeBus[cambio2] >= costeTren[cambio2]) rellenarGrafo(cambio1, cambio2, bus, costesMin);
    else  rellenarGrafo(cambio1, cambio2, tren, costesMin);

    rellenarGrafo(cambio2, destino , bus, costesMin);

    costeTotal = Dijkstra(costesMin, origen, P);
     vector<vertice> camino;

    vertice camin = destino;
    while(camin != origen ){
        camino.insert(camino.begin(), camin);
        camin = P[camin];
    }   

    costes<tCoste> resultado(costeTotal[destino], camino);

    return resultado;
}

template <typename tCoste>
void rellenarGrafo(typename GrafoP<tCoste::vertice> origen,  typename GrafoP<tCoste::vertice> destino, const GrafoP<tCoste>& costes, GrafoP<tCoste>& costesMin){
    typedef typename GrafoP<tCoste::vertice> vertice;
    for(vertice i = origen ; i <= destino; i++){
        for(vertice j = origen ; j <= destino; j++){
            costesMin[i][j] = costes[i][j]; // mirar si tambien hay que hacer [j][i];
            costesMin[j][i] = costes[j][i];
        }
    }

}