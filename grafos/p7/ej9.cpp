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
resultado<tCoste> viaje (const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus,
   typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino, tCoste costeTaxi){

    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<vertice> P, PTren, Pbus, PMinimo; 
    GrafoP<tCoste> minimos(tren.numVert());
    bool esTren;

     for(vertice i = 0; i < tren.numVert(); i++ )
    {
        for(vertice j = 0; j < tren.numVert(); j++ ){
            minimos[i][j] = min(tren[i][j], bus[i][j]);
            if(i == 0 && j == 0){
                if(minimos[i][j] == tren[i][j]) esTren = true;
                else esTren = false;
            }else{
                if(minimos[i][j] == tren[i][j] && esTren == false) {
                    minimos[i][j] += costeTaxi;
                    esTren = true;
                }

                if(minimos[i][j] == bus[i][j] && esTren == true){
                    minimos[i][j] += costeTaxi;
                    esTren = false;
                }
            }
        }
    }
   coste<tCoste> costesTren = Dijkstra(tren, origen, PTren);
   coste<tCoste> costesBus = Dijkstra(tren, origen, PBus);
    coste<tCoste> costesMinimos = Dijkstra(minimos, origen, PMinimo);
coste<tCoste> costes;
    tCoste costesMinimos = min(costesTren[destino], min(costesBus[destino], costesMinimos[destino]));


    switch(costesMinimos){// esto lo hacemos porque puede ocurrir el caso de que salga mejor no hace transbordo a q si haya q hacerlo
        case costesTren[destino]: P = Ptren; costes = costesTren; break;

        case costesBus[destino]: P = PBus; costes = costesBus; break;

        case costesMinimos[destino]: P = PMinimo; costes = costesMinimos; break;
    }

     vector<vertice> camino; 
    
    vertice aux = destino;

    while(aux != origen){
        camino.insert(aux, camino.begin());
        aux = P[aux];
    }

    resultado<tCoste> result(costes[destino], camino);
}