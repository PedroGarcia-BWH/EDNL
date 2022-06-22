#include "../algoritmos/alggrafoPMC.h"
#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/grafoMA.h"
#include <cmath>
#include <iostream>
using namespace std;
typedef double tCoste;

struct ciudad{
    double x,y;
};

tCoste distanciaEuclidea(ciudad c1, ciudad c2){
    return sqrt(pow(c2.x-c1.x,2) + pow(c2.y - c1.y, 2));
}

GrafoP<tCoste> Nozuelandia(const vector<ciudad>& Fobos, const vector<ciudad>& Deimos, const vector<ciudad>& Europa, tCoste costePuente, tCoste costeCarretera, tCoste unidadPuente, tCoste unidadCarretera){
    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> G(Fobos.size() + Deimos.size() + Europa.size());

    rellenarGrafo(G,Fobos,Deimos,Europa, costePuente, costeCarretera, unidadPuente, unidadCarretera);

    GrafoP<tCoste> minimos = Kruskall(G);

    return minimos;
}

void rellenarGrafo(GrafoP<tCoste>& G,const vector<ciudad>& Fobos, const vector<ciudad>& Deimos, const vector<ciudad>& Europa, tCoste costePuente, tCoste costeCarretera, tCoste unidadPuente, tCoste unidadCarretera){
    typedef typename GrafoP<tCoste>::vertice vertice;

    for(vertice i = 0; G.numVert(); i++){
        for(vertice j=0; G.numVert();j++){
            if(i < Fobos.size()){
                if(j < Fobos.size()){ // si i es de Fobos y j tbn es Deimos

                    G[i][j] = distanciaEuclidea(Fobos[i],Fobos[j]) *unidadCarretera + costeCarretera;

                }else{

                    if(j < Fobos.size() + Deimos.size()){ // si I es de Fobos y j es de Deimos

                         G[i][j] = distanciaEuclidea(Fobos[i],Deimos[j]) *unidadPuente + costePuente;
                         
                    }else{//si no es de Europa
                        G[i][j] = distanciaEuclidea(Fobos[i],Europa[j]) *unidadPuente + costePuente;
                    }

                }
            }else if(i < Fobos.size() + Deimos.size()){ //si i es Deimos

                if(j < Fobos.size()){ // si i es de Fobos y j tbn es Deimos

                    G[i][j] = distanciaEuclidea(Deimos[i],Fobos[j]) *unidadPuente + costePuente;

                }else{
                    if(j < Fobos.size() + Deimos.size()){ // si I es de Fobos y j es de Deimos

                         G[i][j] = distanciaEuclidea(Deimos[i],Deimos[j]) *unidadCarretera + costeCarretera;

                    }else{//si jo es de Europa

                        G[i][j] = distanciaEuclidea(Deimos[i],Europa[j]) *unidadPuente + costePuente;

                    }
                }
            }else{
                if(j < Fobos.size()){ // si i es de Fobos y j tbn es Deimos

                    G[i][j] = distanciaEuclidea(Europa[i],Fobos[j]) *unidadPuente + costePuente;

                }else{
                    if(j < Fobos.size() + Deimos.size()){ // si I es de Fobos y j es de Deimos

                         G[i][j] = distanciaEuclidea(Europa[i],Deimos[j])  *unidadPuente + costePuente;

                    }else{//si jo es de Europa

                        G[i][j] = distanciaEuclidea(Europa[i],Europa[j])  *unidadCarretera + costeCarretera;
                    }
                }
            }
        }
    
    }
}