#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/matriz.h"
#include "../algoritmos/alggrafoPMC.h"
#include <vector>
using namespace std;
// en vez de hacer Dikstra n veces en el for vamos a hacer floyd y listo
template <typename tCoste>
tCoste unSoloTransbordo(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus,
    typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino){
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<tCoste> costeTren, costeBus, costeAux, costeAuxTren;
    vector<vertice> P; 

    costeTren = Dijkstra(tren, origen, P);
    costeBus = Dijkstra(bus, origen, P);

    tCoste total = min(costeBus[destino], costeTren[destino]);

    for(vertice i = 0; i<= tren.numVert(); i++){
            costeAuxBus = Dijkstra(tren, i, P);
            costeAuxTren = Dijkstra(bus, i, P);
            total = min(total, costeTren[i] + costeAuxBus[destino]);
            total = min(total, costeBus[i] + costeAuxTren[destino]);
    }

    return total;
}