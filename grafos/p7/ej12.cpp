#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/matriz.h"
#include "../algoritmos/alggrafoPMC.h"
#include <vector>
using namespace std;

template <typename tCoste>
struct puente{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice i,j;
    puente(vertice i, vertice j): i(i), j(j) {}
};

template <typename tCoste>
puente<tCoste> puenteZuelandia(const matriz<tCoste>& Fobos, const matriz<tCoste>& Deimos, const vector<typename GrafoP<tCoste>::vertice>& FobosCostero,
const vector<typename GrafoP<tCoste>::vertice>& DeimosCostero){
     typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> cuidades(Fobos.dimension() + Deimos.dimension());

    for(vertice i = 0; i < cuidades.numVert(); i++){
        for(vertice j = 0; j < cuidades.numVert(); j++){
            cuidades[i][j] = typename GrafoP<tCoste>::INFINITO;
        }
    }

    for(vertice i = 0; i < Fobos.dimension(); i++){
        for(vertice j = 0; j < Fobos.dimension(); j++){
            cuidades[i][j] = Fobos[i][j];
        }
    }


     for(vertice i = Fobos.dimension(); i < Deimos.dimension(); i++){
        for(vertice j = 0; j < Fobos.dimension(); j++){
            cuidades[i][j] = Deimos[i][j];
        }
    }

    vertice cFobos, cDeimos;
    vector<vertice> P;
    matriz<tCoste> costes;
    tCoste costeMin, costeAux;

    cuidades[FobosCostero[0]][Fobos.dimension() +DeimosCostero[0] ] = cuidades[Fobos.dimension() +DeimosCostero[0]][FobosCostero[0]] = 0; //el enunciado nos dice que el coste es 0
    costes = Floyd(cuidades,P);
    costeMin = costeTotal(costes);
    
    cFobos = FobosCostero[0];
    cDeimos = Fobos.dimension() +DeimosCostero[0];


    for(int i = 0 ; i< FobosCostero.size(); i++){
        for(int j = 0; j < DeimosCostero.size(); j++){
            if(i != 0 && j != 0) cuidades[i-1][Fobos.dimension()+j-1] = cuidades[Fobos.dimension()+j-1][i-1] = typename GrafoP<tCoste>::INFINITO; //ponemos el anterior a INFINITO

            if(j == 0 && i != 0) cuidades[i-1][Fobos.dimension()+DeimosCostero[DeimosCostero.size()-1]] = cuidades[Fobos.dimension()+DeimosCostero[DeimosCostero.size()-1]][i-1] = typename GrafoP<tCoste>::INFINITO;
            // como al empezar de nuevo por j tenemos que irnos al i anterior y al ultimo del deimos costero pa ponerlo a INFINITO

            cuidades[i][Fobos.dimension()+j] = cuidades[Fobos.dimension()+j][i] = 0; //el enunciado nos dice que el coste es 0
            costes = Floyd(cuidades,P);
            costeAux = costeTotal(costes);

            if(costesAux < costeMin){
                costeMin = costeAux;
                cFobos = i;
                cDeimos = Fobos.dimension()+j;
            }

        }
    }

    puente<tCoste> result(cFobos, cDeimos);
    return result;

}


template <typename tCoste>
tCoste costeTotal(const matriz<tCoste>& costes){
    tCoste coste = 0;
    for(int i = 0; i< costes.dimension(); i++){
        for(int j = 0; j < costes.dimension(); j++){
            if(costes[i][j] != typename GrafoP<tCoste>::INFINITO) coste += costes[i][j]; // la matriz es simetrica ya que no nos dice nada de un solo sentido asi que da igual pq todas las calculamos igual
        }
    }

    return coste;
}