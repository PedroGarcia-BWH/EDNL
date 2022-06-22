#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/matriz.h"
#include "../algoritmos/alggrafoPMC.h"
#include <vector>
using namespace std;

template <typename tCoste>
struct resultado{
    tCoste costeTotal;
    vector<typename GrafoP<tCoste>::vertice> camino;
    costes(tCoste costeTotal, const vector<typename GrafoP<tCoste>::vertice>& camino): costeTotal(costeTotal), camino(camino) {}
};

template <typename tCoste>

resultado<tCoste> viaje(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus, const GrafoP<tCoste>& avion,
typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino, tCoste taxiTrenBus, tCoste taxiAeroTrenBus){

    typedef typename GrafoP<tCoste>::vertice vertice;

    vector<vertice> P(tren.numVert);
    GrafoP<tCoste> minimos(tren.numVert);

    tCoste minTren, minBus, minAvion;

    size_t medio; // 0 = tren, 1 bus, 2 avion

    minimos = min({ tren[0][0], bus[0][0], avion[0][0]});

     if(i == 0 && j == 0){
                switch(minimos[0][0]){
                    case tren[0][0] : medio = 0; break;
                    case bus[0][0] : medio = 1; break;
                    case avion[0][0] : medio = 2 break;
                }
        }

    for(vertice i = 0; i< tren.numVert(), i++)
    {
        for(vertice j = 0; j< tren.numVert(), j++){

            if(medio == 0){
                minimos[i][j] = min({ tren[i][j], bus[i][j] + taxiTrenBus, avion[i][j] + taxiAeroTrenBus});

                switch(minimos[i][j]){
                    case tren[i][j] : medio = 0; break;
                    case bus[i][j] + taxiAeroBus : medio = 1; break;
                    case avion[i][j] + taxiAeroTrenBus : medio = 2 break;
                }
            }else if(medio == 1){
                 minimos[i][j] = min({ tren[i][j] + taxiTrenBus, bus[i][j] , avion[i][j] + taxiAeroTrenBus});

                switch(minimos[i][j]){
                    case tren[i][j] + taxiAeroBus : medio = 0; break;
                    case bus[i][j]  : medio = 1; break;
                    case avion[i][j] + taxiAeroTrenBus : medio = 2 break;
                }
            } else if(medio == 2){
                   minimos[i][j] = min({ tren[i][j] + taxiAeroTrenBus, bus[i][j] + taxiAeroTrenBus , avion[i][j]});

                switch(minimos[i][j]){
                    case tren[i][j] + taxiAeroTrenBus : medio = 0; break;
                    case bus[i][j] + taxiAeroTrenBus : medio = 1; break;
                    case avion[i][j]  : medio = 2 break;
                }
            }      

        }   
    }

    costes<tCoste> costes = Dijkstra(minimos, origen, P);
    vector<vertice> camino;
    vertice aux = destino;

    while(aux != origen){
        camino.insert(aux, camino.begin());
        aux = P[destino];
    }

    resultado<tCoste> result(costes[destino], camino);

    return result;
}